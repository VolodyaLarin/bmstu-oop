#ifndef REQUEST_HPP_
#define REQUEST_HPP_

struct ReadModelArgs {
  const char *filename;
};

#include "wrapper.hpp"
struct DrawArgs {
  CanvasWrapper canvas;
};

enum action_t {
  action_read_model,
  action_translate,
  action_scale,
  action_rotate,
  action_free_content,
  action_draw,
};

#include "drawer.hpp"

struct Request {
  action_t action;
  union {
    Translate3d translate;
    Scale3d scale;
    Angles3d rotate;
    ReadModelArgs read_model;
    DrawArgs draw_args;
  };
};

#endif