#pragma once

#include "drawer.hpp"

namespace drawer {

int read(DrawerData &data, const char filename[]);
int read_Line3d(FILE *file, Line3d &line);
int read_Cord3d(FILE *file, Cord3d &cord);


void free_content(DrawerData &data);


}  // namespace drawer
