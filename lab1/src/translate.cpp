
#include "translate.hpp"

#include "drawer.hpp"

namespace drawer {

void translate(DrawerData &data, const Cord3d &d) {
  translate_Cord3d(data.center, d);
  for (size_t i = 0; i < data.count; i++) translate_Line3d(data.lines[i], d);
}

void translate_Line3d(Line3d &line, const Cord3d &d) {
  translate_Cord3d(line.start, d);
  translate_Cord3d(line.end, d);
}
void translate_Cord3d(Cord3d &p, const Cord3d &d) {
  p.x = p.x + d.x;
  p.y = p.y + d.y;
  p.z = p.z + d.z;
}

}  // namespace drawer