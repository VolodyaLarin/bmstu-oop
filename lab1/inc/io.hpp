#ifndef IO_HPP_
#define IO_HPP_

#include "drawer.hpp"
#include "request.hpp"

namespace drawer {

int read_model(Model &data, const ReadModelArgs &);
int read_model_from_stream(Model &model, FILE *file);

int read_Cords(Cords3d &cords, FILE *file);
int read_Lines(Lines3d &lines, FILE *file, size_t cords_count);

int read_Line3d(Line3d &line, FILE *file, size_t cords_count);
int read_Cord3d(Cord3d &cord, FILE *file);
int read_size(size_t &size, FILE *file);

void free_content(Model &data);

}  // namespace drawer
#endif