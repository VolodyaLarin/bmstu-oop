#include "rotate.hpp"

#include <cmath>

#include "drawer.hpp"

namespace drawer {

int rotate_model(Model &data, const Cord3d &angles) {
  int err = SUCCESS;
  if (!data.loaded) err = ERROR_NOT_LOAD;
  if (!err)
    for (size_t i = 0; i < data.count_cords; i++) {
      rotate_x_Cord3d(data.cords[i], data.center, angles.x);
      rotate_y_Cord3d(data.cords[i], data.center, angles.y);
      rotate_z_Cord3d(data.cords[i], data.center, angles.z);
    }

  return err;
}

void rotate_x_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.y = (p.y - c.y) * cos(a) - (p.z - c.z) * sin(a) + c.y;
  p.z = (p.y - c.y) * sin(a) + (p.z - c.z) * cos(a) + c.z;
}

void rotate_y_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.x = (p.x - c.x) * cos(a) - (p.z - c.z) * sin(a) + c.x;
  p.z = (p.x - c.x) * sin(a) + (p.z - c.z) * cos(a) + c.z;
}

void rotate_z_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.x = (p.x - c.x) * cos(a) - (p.y - c.y) * sin(a) + c.x;
  p.y = (p.x - c.x) * sin(a) + (p.y - c.y) * cos(a) + c.y;
}

}  // namespace drawer