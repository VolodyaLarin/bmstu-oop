#pragma once

#include "drawer.hpp"

namespace drawer {

int translate_model(Model &data, const Translate3d &d);
void translate_Cord3d(Cord3d &p, const Translate3d &d);

}  // namespace drawer
