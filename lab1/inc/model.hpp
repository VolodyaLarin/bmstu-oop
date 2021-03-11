#pragma once

#include "drawer.hpp"

int init_model(Model &model, size_t cords_count, size_t lines_count);
void free_model(Model &model);
int init_result(DrawerResult &result, const Model &model);
void free_result(DrawerResult &result);
