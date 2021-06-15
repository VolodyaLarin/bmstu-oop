//
// Created by volodya on 09.06.2021.
//

#include "panel.h"
#include "../controller/controller.h"

void Panel::push_button(int floor){
    if (floor < 0 || floor > max_floors)
        return;

    notify(std::make_shared<PushFloorButtonEvent>(floor));
}

Panel::Panel(int maxFloors) : max_floors(maxFloors) {}
