#include "model.hpp"

#include <cstdlib>
#include <cstring>

#include "drawer.hpp"

int init_lines(Lines3d &lines, size_t count){
    auto *temp = (Line3d *)calloc(count, sizeof(Line3d));
    if (!temp) return ERROR_ALLOC;

    lines.array = temp;
    lines.count = count;

    return SUCCESS;
}
int init_cords(Cords3d &cords, size_t count){
    auto *temp = (Cord3d *)calloc(count, sizeof(Cord3d));
    if (!temp) return ERROR_ALLOC;

    cords.array = temp;
    cords.count = count;

    return SUCCESS;
}

void free_cords(Cords3d &cords){
    free(cords.array);

    cords.array = nullptr;
    cords.count = 0;
}

void free_lines(Lines3d &lines){
    free(lines.array);

    lines.array = nullptr;
    lines.count = 0;
}

void free_model(Model &model) {
  free_cords(model.cords);
  free_lines(model.lines);
}


Model init_model(){
    Model model {};
    return model;
}


size_t get_size_cords(const Cords3d &cords){
    return cords.count;
}