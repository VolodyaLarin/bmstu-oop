#ifndef TRANSLATE_HPP_
#define TRANSLATE_HPP_

#include "drawer.hpp"

namespace drawer {

void translate_model(Model &data, const Translate3d &d);
void translate_Cord3d(Cord3d &p, const Translate3d &d);

void translate_cords(Cords3d &cords, const Translate3d &translate);

void translate_model_center(Model &data);
void translate_model_original(Model &data);

}  // namespace drawer

#endif
