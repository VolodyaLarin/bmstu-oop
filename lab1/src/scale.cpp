
#include "scale.hpp"

#include "drawer.hpp"

namespace drawer {

void scale_cords(Cords3d &cords, const Cord3d &center, const Cord3d &k) {
  for (size_t i = 0; i < cords.count; i++)
    scale_Cord3d(cords.array[i], center, k);
}

int scale_model(Model &data, const Cord3d &k) {
  if (data.loaded) return ERROR_NOT_LOAD;

  scale_cords(data.cords, data.center, k);

  return SUCCESS;
}

void scale_Cord3d(Cord3d &point, const Cord3d &center, const Cord3d &k) {
  point.x = k.x * (point.x - center.x) + center.x;
  point.y = k.y * (point.y - center.y) + center.y;
  point.z = k.z * (point.z - center.z) + center.z;
}

}  // namespace drawer