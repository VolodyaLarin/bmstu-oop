
#include "translate.hpp"

#include "drawer.hpp"

namespace drawer {

void translate_model(Model &data, const Translate3d &translate) {
    translate_Cord3d(data.center, translate);
    translate_cords(data.cords, translate);
}


void translate_cords(Cords3d &cords, const Translate3d &translate) {
    for (size_t i = 0; i < cords.count; i++)
        translate_Cord3d(cords.array[i], translate);
}

void translate_Cord3d(Cord3d &cord, const Translate3d &translate) {
  cord.x = cord.x + translate.x;
  cord.y = cord.y + translate.y;
  cord.z = cord.z + translate.z;
}

Translate3d invert_center(const Cord3d &center) {
  Translate3d translate;
  translate.x = -center.x;
  translate.y = -center.y;
  translate.z = -center.z;

  return translate;
}

void translate_model_center(Model &data) {
  Translate3d translate = invert_center(data.center);
  translate_cords(data.cords, translate);
}

void translate_model_original(Model &data) {
  translate_cords(data.cords, data.center);
}

}  // namespace drawer