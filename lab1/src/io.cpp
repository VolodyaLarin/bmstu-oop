
#include "io.hpp"

#include <cstdlib>

#include "drawer.hpp"
#include "model.hpp"

namespace drawer {

int read_model(Model &model, const ReadModelArgs &args) {
  int err = SUCCESS;

  if (model.loaded) err = ERROR_NOT_LOAD;

  FILE *file = nullptr;
  if (!err) file = fopen(args.filename, "r");
  if (!err && !file) err = ERROR_FILE;

  size_t count_cords = 0, count_lines = 0;
  if (!err) err = read_size(count_cords, file);
  if (!err) err = read_size(count_lines, file);

  Model temp_model = {};
  if (!err) init_model(temp_model, count_cords, count_lines);

  if (!err) err = read_Cord3d(temp_model.center, file);

  for (size_t i = 0; !err && i < temp_model.count_cords; i++)
    err = read_Cord3d(temp_model.cords[i], file);

  for (size_t i = 0; !err && i < temp_model.count_lines; i++)
    err = read_Line3d(temp_model.lines[i], file, temp_model.count_cords);

  if (!err)
    model = temp_model;
  else
    free_model(temp_model);

  return err;
}

int read_size(size_t &size, FILE *file) {
  int err = SUCCESS;

  if (!file) {
    err = ERROR_PTR;
  } else {
    long long temp_size = 0;
    if (fscanf(file, "%lld", &temp_size) != 1 || temp_size <= 0)
      err = ERROR_IO;
    else
      size = temp_size;
  }

  return err;
}

int read_Line3d(Line3d &line, FILE *file, size_t cords_count) {
  int err = SUCCESS;
  if (!file) err = ERROR_PTR;

  long long start = 0, end = 0;

  if (!err && fscanf(file, "%lld%lld", &start, &end) != 2) err = ERROR_IO;
  if (!err && (start < 0 || (size_t)start >= cords_count)) err = ERROR_IO;
  if (!err && (end < 0 || (size_t)end >= cords_count)) err = ERROR_IO;

  if (!err) {
    line.start = start;
    line.end = end;
  }

  return err;
}

int read_Cord3d(Cord3d &cord, FILE *file) {
  int err = SUCCESS;
  if (!file) err = ERROR_PTR;

  Cord3d temp = {};

  if (!err && fscanf(file, "%lf%lf%lf", &temp.x, &temp.y, &temp.z) != 3)
    err = ERROR_IO;

  if (!err) cord = temp;

  return err;
}

}  // namespace drawer