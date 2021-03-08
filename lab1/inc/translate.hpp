#pragma once

#include "drawer.hpp"

namespace drawer {

void translate(DrawerData &data, const Cord3d &d);
void translate_Line3d(Line3d &line, const Cord3d &d);
void translate_Cord3d(Cord3d &p, const Cord3d &d);

}  // namespace drawer
