#include "drawer.hpp"

#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

#include "io.hpp"
#include "project.hpp"
#include "rotate.hpp"
#include "scale.hpp"
#include "translate.hpp"

namespace drawer {

int drawer(int action, ...) {
  static DrawerData data = {};

  int err = SUCCESS;

  va_list list;
  va_start(list, action);

  if (action != load_file && !data.lines) err = ERROR_NOT_LOAD;

  if (!err) switch (action) {
      case load_file: {
        char *filename = va_arg(list, char *);
        err = read(data, filename);
        break;
      }
      case action_rotate_x: {
        double angle = va_arg(list, double);
        rotate_x(data, angle);
        break;
      }
      case action_rotate_y: {
        double angle = va_arg(list, double);
        rotate_y(data, angle);
        break;
      }
      case action_rotate_z: {
        double angle = va_arg(list, double);
        rotate_z(data, angle);
        break;
      }

      case action_translate: {
        double x = va_arg(list, double);
        double y = va_arg(list, double);
        double z = va_arg(list, double);
        Cord3d cord = {x, y, z};
        translate(data, cord);
        break;
      }

      case action_scale: {
        double x = va_arg(list, double);
        double y = va_arg(list, double);
        double z = va_arg(list, double);
        Cord3d cord = {x, y, z};
        scale(data, cord);
        break;
      }
      case action_free_content: {
        free_content(data);
        break;
      }
      case action_project: {
        DrawerResult **res = va_arg(list, DrawerResult **);
        project(data);
        if (res)
          *res = &data.result;
        else
          err = ERROR_PTR;

        break;
      }

      default:
        break;
    }

  va_end(list);
  return err;
}

}  // namespace drawer