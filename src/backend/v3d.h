#ifndef SRC_BACKEND_V3D_H_
#define SRC_BACKEND_V3D_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DEFAULT_VNUM 4
#define DEFAULT_FNUM 4
#define DEFAULT_VNUM_IN_FACE 3

/// @file
/// @brief Бэкенд для 3DViewer

#include <ctype.h>
#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

/// @brief Коды ошибок
typedef enum errors {
  OK,
  WRONG_FILENAME,
  MEMORY_ERROR,
  WRONG_FACE,
  INCORRECT_MATRIX,
  CALCULATION_ERROR,
} errors;

/// @brief Структура для хранения координат вершины
typedef struct {
  double x, y, z;
} vertex;

/// @brief Структура для хранения массива вершин грани
typedef struct {
  size_t *vertexes;
  size_t num;
} face;

/// @brief Структура для хранения данных obj-файла
typedef struct {
  vertex *vertexes;
  face *faces;
  size_t vnum, fnum;
  double xmax, xmin, ymax, ymin, zmax, zmin;
} obj;

errors make_obj(obj *ob, const char *filename);
void free_obj(obj *ob);
errors move_obj(obj *ob, const double *xyz);
errors scale_obj(obj *ob, const double *xyz);
errors rotate_obj(obj *ob, const double *xyz);
void set_default_extremes(obj *ob);

#ifdef __cplusplus
}
#endif

#endif  // SRC_BACKEND_V3D_H_
