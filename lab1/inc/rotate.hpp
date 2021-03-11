#pragma once

#include "drawer.hpp"

namespace drawer {

int rotate_model(Model &data, const Angles3d &angles);

void rotate_x_Cord3d(Cord3d &p, const Cord3d &c, double a);
void rotate_y_Cord3d(Cord3d &p, const Cord3d &c, double a);
void rotate_z_Cord3d(Cord3d &p, const Cord3d &c, double a);

}  // namespace drawer
