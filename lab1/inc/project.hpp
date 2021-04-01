#ifndef PROJECT_HPP_
#define PROJECT_HPP_



#include "drawer.hpp"
#include "request.hpp"
#include "wrapper.hpp"

namespace drawer {

    int draw_line_wrapper(CanvasWrapper &canvas, Cord2d proj[2]);

    int draw(DrawArgs &args, const Model &data);
    int draw_lines(CanvasWrapper &canvas, const Lines3d &lines,
                   const Cords3d &cords);

    void project_2cord(Cord2d proj[2], const Cord3d cord[2]);
    void project_cord(Cord2d &proj, const Cord3d &cord);

}  // namespace drawer

#endif