#include "v3d.h"

/// @brief Структура для хранения матрицы
typedef struct {
  double **matrix;
  size_t rows;
  size_t columns;
} matrix;

int is_matrix(matrix *A) {
  return A && A->matrix && A->rows > 0 && A->columns > 0;
}

errors create_matrix(int rows, int columns, matrix *result) {
  errors error = INCORRECT_MATRIX;
  if (result && rows > 0 && columns > 0) {
    error = OK;
    result->columns = columns;
    result->rows = rows;
    result->matrix =
        malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
    if (result->matrix) {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;
      for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j) result->matrix[i][j] = 0.0;
    } else
      error = INCORRECT_MATRIX;
  }
  return error;
}

void remove_matrix(matrix *A) {
  if (A) {
    A->rows = 0;
    A->columns = 0;
    if (A->matrix) free(A->matrix);
    A->matrix = NULL;
  }
}

errors mult_matrix(matrix *A, matrix *B, matrix *result) {
  errors error = INCORRECT_MATRIX;
  if (result && is_matrix(A) && is_matrix(B)) {
    if (A->columns == B->rows) {
      error = create_matrix(A->rows, B->columns, result);
      if (!error)
        for (size_t i = 0; i < A->rows; ++i)
          for (size_t j = 0; j < B->columns; ++j) {
            result->matrix[i][j] = 0;
            for (size_t k = 0; k < A->columns; ++k)
              result->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
          }
    } else
      error = CALCULATION_ERROR;
  }
  return error;
}

// Далее матрицы перехода. Почитать можно, например, в Википедии
// https://ru.wikipedia.org/wiki/Матрица_перехода

errors create_moving_matrix(matrix *m, const double *xyz) {
  errors error = OK;
  error = create_matrix(4, 4, m);
  if (!error) {
    for (size_t i = 0; i < m->rows; ++i) m->matrix[i][i] = 1.0;
    m->matrix[0][3] = xyz[0];
    m->matrix[1][3] = xyz[1];
    m->matrix[2][3] = xyz[2];
  }
  return error;
}

errors create_scaling_matrix(matrix *m, const double *xyz) {
  errors error = OK;
  error = create_matrix(4, 4, m);
  if (!error) {
    m->matrix[0][0] = xyz[0];
    m->matrix[1][1] = xyz[1];
    m->matrix[2][2] = xyz[2];
    m->matrix[3][3] = 1;
  }
  return error;
}

errors create_rotation_X_matrix(matrix *m, const double angle) {
  errors error = OK;
  error = create_matrix(4, 4, m);
  if (!error) {
    m->matrix[0][0] = 1;
    m->matrix[1][1] = cos(angle);
    m->matrix[1][2] = -sin(angle);
    m->matrix[2][1] = sin(angle);
    m->matrix[2][2] = cos(angle);
    m->matrix[3][3] = 1;
  }
  return error;
}

errors create_rotation_Y_matrix(matrix *m, const double angle) {
  errors error = OK;
  error = create_matrix(4, 4, m);
  if (!error) {
    m->matrix[0][0] = cos(angle);
    m->matrix[0][2] = sin(angle);
    m->matrix[1][1] = 1;
    m->matrix[2][0] = -sin(angle);
    m->matrix[2][2] = cos(angle);
    m->matrix[3][3] = 1;
  }
  return error;
}

errors create_rotation_Z_matrix(matrix *m, const double angle) {
  errors error = OK;
  error = create_matrix(4, 4, m);
  if (!error) {
    m->matrix[0][0] = cos(angle);
    m->matrix[0][1] = -sin(angle);
    m->matrix[1][0] = sin(angle);
    m->matrix[1][1] = cos(angle);
    m->matrix[2][2] = 1;
    m->matrix[3][3] = 1;
  }
  return error;
}

errors create_vertex_matrix(matrix *vertex_matrix, const vertex vertex) {
  errors error = OK;
  error = create_matrix(4, 1, vertex_matrix);
  if (!error) {
    vertex_matrix->matrix[0][0] = vertex.x;
    vertex_matrix->matrix[1][0] = vertex.y;
    vertex_matrix->matrix[2][0] = vertex.z;
    vertex_matrix->matrix[3][0] = 1;
  }
  return error;
}
// Конец матриц перехода

void set_vertex(obj *ob, const size_t index, const matrix *m) {
  ob->vertexes[index].x = m->matrix[0][0];
  ob->vertexes[index].y = m->matrix[1][0];
  ob->vertexes[index].z = m->matrix[2][0];
  if (ob->vertexes[index].x > ob->xmax) ob->xmax = ob->vertexes[index].x;
  if (ob->vertexes[index].x < ob->xmin) ob->xmin = ob->vertexes[index].x;
  if (ob->vertexes[index].y > ob->ymax) ob->ymax = ob->vertexes[index].y;
  if (ob->vertexes[index].y < ob->ymin) ob->ymin = ob->vertexes[index].y;
  if (ob->vertexes[index].z > ob->zmax) ob->zmax = ob->vertexes[index].z;
  if (ob->vertexes[index].z < ob->zmin) ob->zmin = ob->vertexes[index].z;
}

void set_default_extremes(obj *ob) {
  ob->xmax = -DBL_MAX;
  ob->xmin = DBL_MAX;
  ob->ymax = -DBL_MAX;
  ob->ymin = DBL_MAX;
  ob->zmax = -DBL_MAX;
  ob->zmin = DBL_MAX;
}

errors transform(obj *ob, matrix *transform_matrix) {
  errors error = OK;
  matrix vertex_matrix, result_matrix;
  set_default_extremes(ob);
  for (size_t i = 0; !error && i < ob->vnum; ++i) {
    error = create_vertex_matrix(&vertex_matrix, ob->vertexes[i]);
    if (!error) {
      error = mult_matrix(transform_matrix, &vertex_matrix, &result_matrix);
      if (!error) set_vertex(ob, i, &result_matrix);
      remove_matrix(&result_matrix);
    }
    remove_matrix(&vertex_matrix);
  }
  return error;
}

/// @brief Перемещает модель
/// @param ob Структура для хранеия данных файла .obj
/// @param xyz Массив содержащий значения сдвигов по координатам x, y, z
/// @return Код ошибки
errors move_obj(obj *ob, const double *xyz) {
  errors error = OK;
  matrix moving_matrix;
  error = create_moving_matrix(&moving_matrix, xyz);
  if (!error) error = transform(ob, &moving_matrix);
  remove_matrix(&moving_matrix);
  return error;
}

/// @brief Масштабирует модель
/// @param ob Структура для хранеия данных файла .obj
/// @param xyz Массив значений масштабных коэффициентов по осям x, y, z
/// @return Код ошибки
errors scale_obj(obj *ob, const double *xyz) {
  errors error = OK;
  matrix scaling_matrix;
  error = create_scaling_matrix(&scaling_matrix, xyz);
  if (!error) error = transform(ob, &scaling_matrix);
  remove_matrix(&scaling_matrix);
  return error;
}

/// @brief Вращает модель
/// @param ob Структура для хранеия данных файла .obj
/// @param xyz Массив значений углов поворота относительно осей x, y, z
/// @return Код ошибки
errors rotate_obj(obj *ob, const double *xyz) {
  errors error = OK;
  matrix rotation_matrix;
  for (size_t i = 0; i < 3; ++i) {
    if (xyz[i] == 0) continue;
    if (i == 0)
      error = create_rotation_X_matrix(&rotation_matrix, xyz[i] * M_PI / 180);
    else if (i == 1)
      error = create_rotation_Y_matrix(&rotation_matrix, xyz[i] * M_PI / 180);
    else
      error = create_rotation_Z_matrix(&rotation_matrix, xyz[i] * M_PI / 180);
    if (!error) error = transform(ob, &rotation_matrix);
    remove_matrix(&rotation_matrix);
  }
  return error;
}
