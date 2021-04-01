#ifndef SCALE_HPP_
#define SCALE_HPP_


#include "drawer.hpp"

namespace drawer {

void scale_model(Model &data, const Scale3d &k);
void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k);

}  // namespace drawer

#endif