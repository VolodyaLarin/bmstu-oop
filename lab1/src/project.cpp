#include "project.hpp"

#include "drawer.hpp"
#include "model.hpp"

namespace drawer {

void getLineCords(Cord3d cord[2], const Line3d line, const Cords3d &cords) {
  cord[0] = cords.array[line.start];
  cord[1] = cords.array[line.end];
}

int draw(DrawArgs &args, const Model &data) {
  return draw_lines(args.canvas, data.lines, data.cords);
}

int draw_lines(CanvasWrapper &canvas, const Lines3d &lines,
               const Cords3d &cords) {
  Cord3d cords_line3d[2] = {};
  Cord2d cords_line2d[2] = {};

  int err = SUCCESS;

  for (size_t i = 0; !err && i < lines.count; i++) {
    getLineCords(cords_line3d, lines.array[i], cords);
    project_2cord(cords_line2d, cords_line3d);
    err = draw_line_wrapper(canvas, cords_line2d);
  }

  return err;
}

int draw_line_wrapper(CanvasWrapper &canvas, Cord2d proj[2]) {
  try {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(proj[0].x, proj[0].y)),
        sf::Vertex(sf::Vector2f(proj[1].x, proj[1].y)),
    };
    canvas.window->draw(line, 2, sf::Lines);
  } catch (const std::exception &e) {
    return EXIT_FAILURE;
  }

  return SUCCESS;
}

void project_2cord(Cord2d proj[2], const Cord3d cord[2]) {
  project_cord(proj[0], cord[0]);
  project_cord(proj[1], cord[1]);
}

void project_cord(Cord2d &proj, const Cord3d &cord) {
  proj.x = cord.x;
  proj.y = cord.y;
}
}  // namespace drawer
