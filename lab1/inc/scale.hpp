#pragma once

#include "drawer.hpp"

namespace drawer {

int scale_model(Model &data, const Scale3d &k);
void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k);

}  // namespace drawer
