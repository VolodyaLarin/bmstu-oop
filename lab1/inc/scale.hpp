#pragma once

#include "drawer.hpp"

namespace drawer {

void scale(DrawerData &data, const Cord3d &k);
void scale_Line3d(Line3d &line, const Cord3d &center, const Cord3d &k);
void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k);

}  // namespace drawer
