#include "model.hpp"

#include <cstdlib>
#include <cstring>

#include "drawer.hpp"

int init_model(Model &model, size_t cords_count, size_t lines_count) {
  Model model_temp;

  model_temp.loaded = true;

  model_temp.count_cords = cords_count;
  model_temp.count_lines = lines_count;

  model_temp.center = {};

  model_temp.cords = (Cord3d *)calloc(cords_count, sizeof(*model_temp.cords));
  model_temp.lines = (Line3d *)calloc(lines_count, sizeof(*model_temp.cords));

  int err = SUCCESS;
  if (!model_temp.cords || !model_temp.lines) {
    err = ERROR_ALLOC;
    free_model(model_temp);
  }

  if (!err) model = model_temp;
  return err;
}

int init_result(DrawerResult &result, const Model &model) {
  DrawerResult temp;

  temp.loaded = true;

  temp.cords_count = model.count_cords;
  temp.lines_count = model.count_lines;

  temp.cords = (Cord2d *)calloc(temp.cords_count, sizeof(*temp.cords));
  temp.lines = (Line *)calloc(temp.lines_count, sizeof(*temp.lines));

  int err = SUCCESS;
  if (!temp.cords || !temp.lines) err = ERROR_ALLOC;

  if (!err)
    memcpy(temp.lines, model.lines, temp.lines_count * sizeof(*temp.lines));

  if (!err)
    result = temp;
  else
    free_result(temp);

  return err;
}

void free_model(Model &model) {
  model.loaded = false;

  free(model.lines);
  free(model.cords);
}

void free_result(DrawerResult &result) {
  result.loaded = false;

  free(result.lines);
  free(result.cords);
}
