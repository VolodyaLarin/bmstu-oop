//
// Created by volodya on 09.06.2021.
//

#include "floor_button.h"
#include "../controller/controller.h"

FloorButton::FloorButton(int floor) {
    _floor = floor;
}

void FloorButton::push() {
    notify(std::make_shared<PushFloorButtonEvent>(_floor));
}

int FloorButton::get_floor() const {
    return _floor;
}

void FloorButton::set_floor(int floor) {
    _floor = floor;
}
