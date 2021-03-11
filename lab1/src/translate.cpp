
#include "translate.hpp"

#include "drawer.hpp"

namespace drawer {

int translate_model(Model &data, const Translate3d &translate) {
  int err = SUCCESS;
  if (!data.loaded) err = ERROR_NOT_LOAD;
  if (!err) translate_Cord3d(data.center, translate);
  if (!err)
    for (size_t i = 0; i < data.count_cords; i++)
      translate_Cord3d(data.cords[i], translate);

  return err;
}

void translate_Cord3d(Cord3d &cord, const Translate3d &translate) {
  cord.x = cord.x + translate.x;
  cord.y = cord.y + translate.y;
  cord.z = cord.z + translate.z;
}

}  // namespace drawer