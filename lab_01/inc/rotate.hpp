#ifndef ROTATE_HPP_
#define ROTATE_HPP_

#include "drawer.hpp"

namespace drawer {

int rotate_model(Model &data, const Angles3d &angles);

void rotate_x_Cord3d(Cord3d &cord, double angle);
void rotate_y_Cord3d(Cord3d &cord, double angle);
void rotate_z_Cord3d(Cord3d &cord, double angle);

}  // namespace drawer

#endif