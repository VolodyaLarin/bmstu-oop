#pragma once

#include "drawer.hpp"

namespace drawer {

void project(const DrawerData &data);
void project_line(const Line3d &line, Line2d &proj);
void project_cord(const Cord3d &cord, Cord2d &proj);

}  // namespace drawer
