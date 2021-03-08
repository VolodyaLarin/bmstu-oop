
#include "scale.hpp"

#include "drawer.hpp"

namespace drawer {

void scale(DrawerData &data, const Cord3d &k) {
  for (size_t i = 0; i < data.count; i++)
    scale_Line3d(data.lines[i], data.center, k);
}

void scale_Line3d(Line3d &line, const Cord3d &center, const Cord3d &k) {
  scale_Cord3d(line.start, center, k);
  scale_Cord3d(line.end, center, k);
}
void scale_Cord3d(Cord3d &p, const Cord3d &c, const Cord3d &k) {
  p.x = k.x * (p.x - c.x) + c.x;
  p.y = k.y * (p.y - c.y) + c.y;
  p.z = k.z * (p.z - c.z) + c.z;
}
}  // namespace drawer