#include "drawer.hpp"

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "io.hpp"
#include "model.hpp"
#include "project.hpp"
#include "rotate.hpp"
#include "scale.hpp"
#include "translate.hpp"

namespace drawer {

int drawer(Request &request) {
  static Model data = init_model();

  int err = SUCCESS;
  switch (request.action) {
    case action_read_model:
      err = read_model(data, request.read_model);
      break;
    case action_rotate:
      err = rotate_model(data, request.rotate);
      break;
    case action_translate:
      err = translate_model(data, request.translate);
      break;
    case action_scale:
      err = scale_model(data, request.scale);
      break;
    case action_free_content:
      free_model(data);
      break;
    case action_draw:
      err = draw(request.draw_args, data);
      break;
    default:
      err = ERROR_UNDEFINED_ACTION;
      break;
  }

  return err;
}

}  // namespace drawer