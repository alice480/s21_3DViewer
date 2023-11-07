#include "v3d.h"

errors enlarge_vertex_array(vertex **array, size_t *size) {
  errors error = OK;
  size_t size_tmp = *size * 2;
  vertex *array_tmp = realloc(*array, size_tmp * sizeof(vertex));
  if (array_tmp) {
    *array = array_tmp;
    *size = size_tmp;
  } else
    error = MEMORY_ERROR;
  return error;
}

errors enlarge_face_array(face **array, size_t *size) {
  errors error = OK;
  size_t size_tmp = *size * 2;
  face *array_tmp = realloc(*array, size_tmp * sizeof(face));
  if (array_tmp) {
    *array = array_tmp;
    *size = size_tmp;
  } else
    error = MEMORY_ERROR;
  return error;
}

errors enlarge_size_t_array(size_t **array, size_t *size) {
  errors error = OK;
  size_t size_tmp = *size * 2;
  size_t *array_tmp = realloc(*array, size_tmp * sizeof(size_t));
  if (array_tmp) {
    *array = array_tmp;
    *size = size_tmp;
  } else
    error = MEMORY_ERROR;
  return error;
}

errors add_vertex(char *str, obj *ob) {
  errors error = OK;
  double xyz[3] = {0};
  char *str_end = NULL;
  for (size_t i = 0, stop = 0; !stop && i < 3; ++i) {
    xyz[i] = strtod(str, &str_end);
    if (str_end == str)
      stop = 1;
    else
      str = str_end;
  }
  ob->vertexes[ob->vnum].x = xyz[0];
  ob->vertexes[ob->vnum].y = xyz[1];
  ob->vertexes[ob->vnum].z = xyz[2];
  if (xyz[0] > ob->xmax) ob->xmax = xyz[0];
  if (xyz[0] < ob->xmin) ob->xmin = xyz[0];
  if (xyz[1] > ob->ymax) ob->ymax = xyz[1];
  if (xyz[1] < ob->ymin) ob->ymin = xyz[1];
  if (xyz[2] > ob->zmax) ob->zmax = xyz[2];
  if (xyz[2] < ob->zmin) ob->zmin = xyz[2];
  ob->vnum++;
  return error;
}

errors add_face(char *str, obj *ob) {
  errors error = OK;
  size_t vsize = DEFAULT_VNUM_IN_FACE;
  ob->faces[ob->fnum].vertexes = calloc(vsize, sizeof(size_t));
  ob->faces[ob->fnum].num = 0;
  char *str_end = NULL;
  for (size_t stop = 0; !stop && !error;) {
    long vertex = strtol(str, &str_end, 10);
    if (vertex) {
      while (!error && vsize <= ob->faces[ob->fnum].num)
        error = enlarge_size_t_array(&(ob->faces[ob->fnum].vertexes), &vsize);
      if (vertex > 0 && (size_t)vertex <= ob->vnum)
        ob->faces[ob->fnum].vertexes[ob->faces[ob->fnum].num++] = vertex - 1;
      else if (vertex < 0 && (long)ob->vnum + vertex > 0)
        ob->faces[ob->fnum].vertexes[ob->faces[ob->fnum].num++] =
            ob->vnum + vertex;
      else
        error = WRONG_FACE;
      str = str_end;
      while (*str != '\0' && !isspace(*str)) str++;
    } else
      stop = 1;
  }
  ob->fnum++;
  return error;
}

/// @brief Заполняет структуру даннами из файла
/// @param ob Структура для хранеия данных файла .obj
/// @param filename Имя файла .obj
/// @return Код ошибки
errors make_obj(obj *ob, const char *filename) {
  errors error = OK;
  setlocale(LC_NUMERIC, "en_US.UTF-8");
  FILE *fd = fopen(filename, "r");
  if (fd) {
    char *str = NULL;
    size_t n = 0;
    size_t vsize = DEFAULT_VNUM;
    size_t fsize = DEFAULT_FNUM;
    ob->vertexes = calloc(vsize, sizeof(vertex));
    ob->faces = calloc(fsize, sizeof(face));
    while (!error && getline(&str, &n, fd) != -1) {
      size_t i = 0;
      while (isspace(str[i])) i++;
      if (str[i] == 'v' && isspace(str[i + 1])) {
        while (!error && vsize <= ob->vnum)
          error = enlarge_vertex_array(&(ob->vertexes), &vsize);
        error = add_vertex(str + i + 1, ob);
      } else if (str[i] == 'f') {
        while (!error && fsize <= ob->fnum)
          error = enlarge_face_array(&(ob->faces), &fsize);
        error = add_face(str + i + 1, ob);
      }
    }
    free(str);
    fclose(fd);
  } else {
    error = WRONG_FILENAME;
  }
  return error;
}

/// @brief Освобождает занятые ресурсы
/// @param ob Структура для хранеия данных файла .obj
void free_obj(obj *ob) {
  if (ob->vertexes) free(ob->vertexes);
  if (ob->faces) {
    for (size_t i = 0; i < ob->fnum; ++i)
      if (ob->faces[i].vertexes) free(ob->faces[i].vertexes);
    free(ob->faces);
  }
  set_default_extremes(ob);
  ob->fnum = 0;
  ob->vnum = 0;
  ob->faces = NULL;
  ob->vertexes = NULL;
}
