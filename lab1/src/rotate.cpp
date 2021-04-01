#include "rotate.hpp"

#include <cmath>

#include "drawer.hpp"
#include "translate.hpp"

namespace drawer {


void rotate_cords(Cords3d &cords, const Cord3d &angles)
{
    for (size_t i = 0; i < cords.count; i++) {
        rotate_x_Cord3d(cords.array[i], angles.x);
        rotate_y_Cord3d(cords.array[i], angles.y);
        rotate_z_Cord3d(cords.array[i], angles.z);
    }
}
void rotate_model(Model &data, const Cord3d &angles) {
    translate_model_center(data);
    rotate_cords(data.cords, angles);
    translate_model_original(data);
}



void rotate_x_Cord3d(Cord3d &cord, double angle) {
  cord.y = cord.y * cos(angle) - cord.z * sin(angle);
  cord.z = cord.y * sin(angle) + cord.z * cos(angle);
}

void rotate_y_Cord3d(Cord3d &cord, double angle) {
  cord.x = cord.x * cos(angle) - cord.z * sin(angle);
  cord.z = cord.x * sin(angle) + cord.z * cos(angle);
}

void rotate_z_Cord3d(Cord3d &cord, double angle) {
  cord.x = cord.x * cos(angle) - cord.y * sin(angle);
  cord.y = cord.x * sin(angle) + cord.y * cos(angle);
}

}  // namespace drawer