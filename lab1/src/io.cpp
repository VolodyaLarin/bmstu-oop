
#include "io.hpp"

#include <cstdlib>

#include "drawer.hpp"

namespace drawer {

int read(DrawerData &data, const char filename[]) {
  int err = SUCCESS;

  FILE *file = fopen(filename, "r");
  if (!file) err = ERROR_FILE;

  if (!err) err = read_Cord3d(file, data.center);

  data.count = 0;
  data.result.count = 0;
  data.lines = nullptr;
  data.result.lines = nullptr;

  if (!err && (fscanf(file, "%zu", &data.count) != 1 || data.count <= 0))
    err = ERROR_IO;
  if (!err) data.result.count = data.count;

  if (!err) data.lines = (Line3d *)malloc(sizeof(Line3d) * data.count);
  if (!err) data.result.lines = (Line2d *)malloc(sizeof(Line2d) * data.count);

  if (!err && (!data.lines || !data.result.lines)) err = ERROR_PTR;

  for (size_t i = 0; !err && i < data.count; i++)
    err = read_Line3d(file, data.lines[i]);

  if (err) free_content(data);

  return err;
}

int read_Line3d(FILE *file, Line3d &line) {
  int err = SUCCESS;
  if (!file) err = ERROR_PTR;

  if (!err) err = read_Cord3d(file, line.start);
  if (!err) err = read_Cord3d(file, line.end);

  return err;
}

int read_Cord3d(FILE *file, Cord3d &cord) {
  int err = SUCCESS;
  if (!file) err = ERROR_PTR;
  if (!err && fscanf(file, "%lf%lf%lf", &cord.x, &cord.y, &cord.z) != 3)
    err = ERROR_IO;
  return err;
}

void free_content(DrawerData &data) {
  free(data.lines);
  free(data.result.lines);

  data.lines = nullptr;
  data.result.lines = nullptr;
}

}  // namespace drawer