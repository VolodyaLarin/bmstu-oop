#include "project.hpp"

#include "drawer.hpp"
#include "model.hpp"

namespace drawer {

int project(DrawerResult &result, const Model &data) {
  int err = SUCCESS;
  if (!data.loaded) err = ERROR_NOT_LOAD;
  if (!err && !result.loaded) err = init_result(result, data);

  if (!err)
    for (size_t i = 0; i < data.count_cords; i++)
      project_cord(result.cords[i], data.cords[i]);

  return err;
}

void project_cord(Cord2d &proj, const Cord3d &cord) {
  proj.x = cord.x;
  proj.y = cord.y;
}
}  // namespace drawer
