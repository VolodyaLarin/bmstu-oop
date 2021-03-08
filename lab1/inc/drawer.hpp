#pragma once

#include <cstddef>
#include <cstdio>

#define SUCCESS 0
#define ERROR_IO -2
#define ERROR_FILE -3
#define ERROR_PTR -3
#define ERROR_NOT_LOAD -3

struct Cord3d {
  double x;
  double y;
  double z;
};
struct Line3d {
  Cord3d start;
  Cord3d end;
};

struct Cord2d {
  double x;
  double y;
};
struct Line2d {
  Cord2d start;
  Cord2d end;
};

struct DrawerResult {
  Line2d *lines;
  size_t count;
};

struct DrawerData {
  Line3d *lines;
  Cord3d center;
  size_t count;
  DrawerResult result;
};

enum action_t {
  load_file,
  action_translate,
  action_scale,
  action_rotate_x,
  action_rotate_y,
  action_rotate_z,
  action_free_content,
  action_project,
};

namespace drawer {

int drawer(int action, ...);

}  // namespace drawer
