//
// Created by volodya on 06.06.2021.
//

#include "doors.h"
#include "../cabin/cabin.h"

#include "iostream"

void Doors::on_cabin_stopped(const Event& event) {
    if (_state == opened || _state == opening) return;

    size_t time = action_time;
    if (_state == closing)
    {
        time = _timer_close.stop();
    }
    std::cout << "Двери открываются" << std::endl;
    _timer_open.start(time);
    _state = opening;
}

void Doors::on_timer_close(const Event& event) {
    if (_state != closing) return;
    _state = closed;

    notify(std::make_shared<DoorsClosedEvent>());
}

void Doors::on_timer_open(const Event& event) {
    if (_state != opening) return;
    _state = opened;

    std::cout << "Двери открылись" << std::endl;
    _timer_waiting.start(waiting_time);
}

void Doors::on_timer_waiting(const Event& event) {
    if (_state != opened) return;;
    _state = closing;

    std::cout << "Двери закрываются" << std::endl;
    _timer_close.start(action_time);
}

Doors::Doors(Cabin &cabin) {
    SUBSCRIBE(_timer_close, TimerEvent(), *this, on_timer_close);
    SUBSCRIBE(_timer_open, TimerEvent(), *this, on_timer_open);
    SUBSCRIBE(_timer_waiting, TimerEvent(), *this, on_timer_waiting);
    SUBSCRIBE(cabin, CabinStoppedEvent(), *this, on_cabin_stopped);
}
