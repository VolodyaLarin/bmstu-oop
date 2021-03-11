#pragma once

#include <cstddef>
#include <cstdio>

#define SUCCESS 0
#define ERROR_IO -2
#define ERROR_FILE -3
#define ERROR_PTR -4
#define ERROR_NOT_LOAD -5
#define ERROR_ALLOC -6
#define ERROR_UNDEFINED_ACTION -7

struct Cord3d {
  double x;
  double y;
  double z;
};
typedef Cord3d Angles3d, Translate3d, Scale3d;

struct Cord2d {
  double x;
  double y;
};

struct Line {
  int start;
  int end;
};

typedef Line Line3d, Line2d;

struct DrawerResult {
  bool loaded;
  Line2d *lines;
  size_t lines_count;

  Cord2d *cords;
  size_t cords_count;
};

struct Model {
  bool loaded;
  Cord3d center;
  Cord3d *cords;
  size_t count_cords;
  Line3d *lines;
  size_t count_lines;
};

#include "request.hpp"


namespace drawer {

int drawer(Request &request);

}  // namespace drawer

