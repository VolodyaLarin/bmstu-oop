
#include "scale.hpp"

#include "drawer.hpp"

namespace drawer {

void scale_cords(Cords3d &cords, const Cord3d &center, const Cord3d &k) {
  for (size_t i = 0; i < cords.count; i++)
    scale_Cord3d(cords.array[i], center, k);
}

void scale_model(Model &data, const Cord3d &k) {
  scale_cords(data.cords, data.center, k);
}

void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k) {
  p.x = k.x * (p.x - c.x) + c.x;
  p.y = k.y * (p.y - c.y) + c.y;
  p.z = k.z * (p.z - c.z) + c.z;
}

}  // namespace drawer