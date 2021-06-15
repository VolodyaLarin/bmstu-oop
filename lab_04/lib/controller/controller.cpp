//
// Created by volodya on 07.06.2021.
//

#include <iostream>
#include "controller.h"

Controller::Controller(Cabin &cabin, const std::vector<IPublisher *> &publishers, int floors) {
    _floors.resize(floors);

    for (int i = 0; i < floors; ++i) {
        _floors[i] = false;
    }

    SUBSCRIBE(cabin, CabinWaitingEvent(), *this, on_cabin_waiting);
    for (auto &p: publishers) {
        SUBSCRIBE(*p, PushFloorButtonEvent(), *this, on_pushing_button);
    }
}

void Controller::on_pushing_button(const PushFloorButtonEvent &e) {
    std::cout << "Нажата кнопка вызова на " << e.floor << " этаж" << std::endl;
    _floors[e.floor] = true;

    if (_state == waiting)
    {
        _destination_floor = e.floor;
        notify(std::make_shared<SettingDestinationEvent>(e.floor));
    }
    if (_destination_floor == e.floor && _state == busy)
    {
        notify(std::make_shared<NeedOpenEvent>());
    }

    _state = busy;
}

void Controller::on_cabin_waiting(const CabinWaitingEvent &e) {
    if (_state != busy) return;
    _state = waiting;

    _floors[e.floor] = false;
    int new_floor = -1;
    int cur_dir = e.direction == CabinWaitingEvent::up ? 1 : -1;
    for (int k = 0; k < 2 && new_floor < 0; ++k) {
        for (int i = e.floor; i >= 0 && i < _floors.size() && new_floor < 0; i += cur_dir) {
            if (_floors[i]) new_floor = i;
        }
        cur_dir *= -1;
    }

    if (new_floor > 0) {
        _destination_floor = new_floor;
        notify(std::make_shared<SettingDestinationEvent>(new_floor));
    }
}
