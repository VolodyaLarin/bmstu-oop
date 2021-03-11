
#include "scale.hpp"

#include "drawer.hpp"

namespace drawer {

int scale_model(Model &data, const Cord3d &k) {
  int err = SUCCESS;
  if (!data.loaded) err = ERROR_NOT_LOAD;
  if (!err)
    for (size_t i = 0; i < data.count_cords; i++)
      scale_Cord3d(data.cords[i], data.center, k);

  return err;
}

void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k) {
  p.x = k.x * (p.x - c.x) + c.x;
  p.y = k.y * (p.y - c.y) + c.y;
  p.z = k.z * (p.z - c.z) + c.z;
}
}  // namespace drawer