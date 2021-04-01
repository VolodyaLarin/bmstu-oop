#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "drawer.hpp"

Model init_model();

int init_lines(Lines3d &lines, size_t count);
int init_cords(Cords3d &cords, size_t count);

void free_model(Model &model);
void free_cords(Cords3d &cords);
void free_lines(Lines3d &lines);

size_t get_size_cords(const Cords3d &cords);
#endif