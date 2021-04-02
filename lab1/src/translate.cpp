
#include "translate.hpp"

#include "drawer.hpp"

namespace drawer {

int translate_model(Model &model, const Translate3d &translate) {
  if (!model.loaded) return ERROR_NOT_LOAD;

  translate_Cord3d(model.center, translate);
  translate_cords(model.cords, translate);

  return SUCCESS;
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

static Translate3d invert_center(const Cord3d &center) {
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