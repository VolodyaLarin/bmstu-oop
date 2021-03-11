#pragma once

#include "drawer.hpp"

struct ReadModelArgs {
  const char *filename;
};

struct ProjectArgs {
  DrawerResult *result;
};

enum action_t {
  action_read_model,
  action_translate,
  action_scale,
  action_rotate,
  action_free_content,
  action_project,
};

struct Request {
  action_t action;
  union {
    Translate3d translate;
    Scale3d scale;
    Angles3d rotate;
    ReadModelArgs read_model;
    ProjectArgs project;
  };
};
