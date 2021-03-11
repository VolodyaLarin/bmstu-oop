#pragma once

#include "drawer.hpp"

namespace drawer {

int read_model(Model &data, const ReadModelArgs&);
int read_Line3d(Line3d &line, FILE *file, size_t cords_count);
int read_Cord3d(Cord3d &cord, FILE *file);
int read_size(size_t &size, FILE *file);

void free_content(Model &data);


}  // namespace drawer
