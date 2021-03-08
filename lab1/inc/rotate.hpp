#pragma once

#include "drawer.hpp"

namespace drawer {

void rotate_x(DrawerData &data, double angle);
void rotate_y(DrawerData &data, double angle);
void rotate_z(DrawerData &data, double angle);
void rotate_x_Line3d(Line3d &line, const Cord3d &center, double angle);
void rotate_y_Line3d(Line3d &line, const Cord3d &center, double angle);
void rotate_z_Line3d(Line3d &line, const Cord3d &center, double angle);
void rotate_x_Cord3d(Cord3d &p, const Cord3d &c, double a);
void rotate_y_Cord3d(Cord3d &p, const Cord3d &c, double a);
void rotate_z_Cord3d(Cord3d &p, const Cord3d &c, double a);

}  // namespace drawer
