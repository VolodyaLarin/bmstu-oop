#pragma once

#include "drawer.hpp"

namespace drawer {

int project(DrawerResult &result, const Model &data);
void project_cord(Cord2d &proj, const Cord3d &cord);

}  // namespace drawer
