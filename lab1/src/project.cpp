#include "project.hpp"

#include "drawer.hpp"

namespace drawer {

void project(const DrawerData &data) {
  for (size_t i = 0; i < data.result.count; i++)
    project_line(data.lines[i], data.result.lines[i]);
}

void project_line(const Line3d &line, Line2d &proj) {
  project_cord(line.start, proj.start);
  project_cord(line.end, proj.end);
}

void project_cord(const Cord3d &cord, Cord2d &proj) {
  proj.x = cord.x;
  proj.y = cord.y;
}
}  // namespace drawer
