
#include "io.hpp"

#include <cstdlib>

#include "drawer.hpp"
#include "model.hpp"

namespace drawer {

int read_model(Model &model, const ReadModelArgs &args) {

  FILE *file = fopen(args.filename, "r");
  if (!file) return ERROR_FILE;

  int err = read_model_from_stream(model, file);

  fclose(file);
  return err;
}

int read_model_from_stream(Model &model, FILE *file) {
  if (!file) return ERROR_PTR;

  Model temp = init_model();

  int err = read_Cord3d(temp.center, file);
   

  if (!err) err = read_Cords(temp.cords, file);

  size_t cords_count = get_size_cords(temp.cords);

  if (!err) err = read_Lines(temp.lines, file, cords_count);

  if (err) {
      free_model(temp);
  } else {
      free_model(model);
      model = temp;
  }
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

int read_Lines(Lines3d &lines, FILE *file, size_t cords_count)
{
    size_t size = 0;
    int err = read_size(size, file);
    Lines3d temp_lines = {};
    if (!err) err = init_lines(temp_lines, size);

    for (size_t i = 0; !err && i < size; ++i) {
        err = read_Line3d(temp_lines.array[i], file, cords_count);
    }

    if (err) {
        free_lines(temp_lines);
    } else {
        free_lines(lines);
        lines = temp_lines;
    }

    return err;
}


int read_Cords(Cords3d &cords, FILE *file)
{
    size_t size = 0;
    int err = read_size(size, file);
    Cords3d temp_cords = {};
    if (!err) err = init_cords(temp_cords, size);

    for (size_t i = 0; !err && i < size; ++i)
        err = read_Cord3d(temp_cords.array[i], file);

    if (err) {
        free_cords(temp_cords);
    } else {
        free_cords(cords);
        cords = temp_cords;
    }

    return err;
}

int read_Line3d(Line3d &line, FILE *file, size_t cords_count) {
    if (!file) return ERROR_PTR;

    long long start = 0, end = 0;

    if (fscanf(file, "%lld%lld", &start, &end) != 2) return ERROR_IO;
    if (start < 0 || (size_t)start >= cords_count) return ERROR_IO;
    if (end < 0 || (size_t)end >= cords_count) return ERROR_IO;

    line.start = start;
    line.end = end;

    return SUCCESS;
}

int read_Cord3d(Cord3d &cord, FILE *file) {
  if (!file) return ERROR_PTR;

  Cord3d temp = {};

  if (fscanf(file, "%lf%lf%lf", &temp.x, &temp.y, &temp.z) != 3)
    return ERROR_IO;

  cord = temp;

  return SUCCESS;
}

}  // namespace drawer