#include "rotate.hpp"

#include <cmath>

#include "drawer.hpp"

namespace drawer {

void rotate_x(DrawerData &data, double angle) {
  for (size_t i = 0; i < data.count; i++)
    rotate_x_Line3d(data.lines[i], data.center, angle);
}
void rotate_y(DrawerData &data, double angle) {
  for (size_t i = 0; i < data.count; i++)
    rotate_y_Line3d(data.lines[i], data.center, angle);
}
void rotate_z(DrawerData &data, double angle) {
  for (size_t i = 0; i < data.count; i++)
    rotate_z_Line3d(data.lines[i], data.center, angle);
}

void rotate_x_Line3d(Line3d &line, const Cord3d &center, double angle) {
  rotate_x_Cord3d(line.start, center, angle);
  rotate_x_Cord3d(line.end, center, angle);
}
void rotate_y_Line3d(Line3d &line, const Cord3d &center, double angle) {
  rotate_y_Cord3d(line.start, center, angle);
  rotate_y_Cord3d(line.end, center, angle);
}

void rotate_z_Line3d(Line3d &line, const Cord3d &center, double angle) {
  rotate_z_Cord3d(line.start, center, angle);
  rotate_z_Cord3d(line.end, center, angle);
}

void rotate_x_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.y = (p.y - c.y) * cos(a) - (p.z - c.z) * sin(a) + c.y;
  p.z = (p.y - c.y) * sin(a) + (p.z - c.z) * cos(a) + c.z;
}

void rotate_y_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.x = (p.x - c.x) * cos(a) - (p.z - c.z) * sin(a) + c.x;
  p.z = (p.x - c.x) * sin(a) + (p.z - c.z) * cos(a) + c.z;
}

void rotate_z_Cord3d(Cord3d &p, const Cord3d &c, double a) {
  p.x = (p.x - c.x) * cos(a) - (p.y - c.y) * sin(a) + c.x;
  p.y = (p.x - c.x) * sin(a) + (p.y - c.y) * cos(a) + c.y;
}

}  // namespace drawer