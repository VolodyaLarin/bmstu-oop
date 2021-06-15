//
// Created by volodya on 06.06.2021.
//

#include <iostream>

#include "cabin.h"
#include "../controller/controller.h"

#include <iostream>

Cabin::Cabin(): doors(*this) {
    SUBSCRIBE(doors, DoorsClosedEvent(), *this, on_doors_closed);
    SUBSCRIBE(_timer_floor_moved, TimerEvent(), *this, on_timer_floor_moved);
    SUBSCRIBE(*this, CabinStoppedEvent(), *this, on_cabin_stopped);
}
void Cabin::subscribe_controller(Controller &controller) {
    SUBSCRIBE(controller, SettingDestinationEvent(), *this, on_setting_destination);
    SUBSCRIBE(controller, NeedOpenEvent(), *this, on_need_open);
}

void Cabin::on_doors_closed(const Event& event) {
    if (_state != stopped) return;
    _state = waiting;

    std::cout << "Двери закрылись" << std::endl;
    notify(std::make_shared<CabinWaitingEvent>(
            _current_floor,
            _current_floor - _previous_floor > 0 ? CabinWaitingEvent::up: CabinWaitingEvent::down)
    );
}

void Cabin::on_timer_floor_moved(const Event& event) {
    if (_state != moves) return;
    _state = moves;

    _previous_floor = _current_floor;

    if (_destination_floor != _current_floor)
    {
        if (_destination_floor > _current_floor) _current_floor++;
        else _current_floor--;
    }

    std::cout << "Лифт на " << _current_floor << " этаже" << std::endl;

    if (_destination_floor == _current_floor)
    {
        notify(std::make_shared<CabinStoppedEvent>());
    }
    else{
        _timer_floor_moved.start(moving_time);
    }
}



void Cabin::on_setting_destination(const SettingDestinationEvent &event) {
    if (_state != waiting) return;
    _state = moves;

    _destination_floor = event.floor;
    std::cout << "Лифт едет на " << event.floor << " этаж" << std::endl;
    _timer_floor_moved.start(moving_time);
}

void Cabin::on_need_open(const NeedOpenEvent &event) {
    if (_state != stopped) return;
    _state = stopped;

    notify(std::make_shared<CabinStoppedEvent>());
}

void Cabin::on_cabin_stopped(const CabinStoppedEvent &event) {
    if (_state != moves) return;

    _state = stopped;
}

