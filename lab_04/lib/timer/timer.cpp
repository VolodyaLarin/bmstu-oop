//
// Created by volodya on 06.06.2021.
//

#include <thread>
#include "timer.h"

void Timer::start(size_t ms) {
    if (_state == waiting)
        return;

    _state = waiting;
    _start = std::chrono::high_resolution_clock::now();
    auto cur_start = _start;

    std::thread([this, cur_start, ms]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        if (_state != stopped && cur_start == _start) {
            _state = stopped;
            notify(std::make_shared<TimerEvent>());
        }
    }).detach();
}

size_t Timer::stop() {
    std::chrono::duration<double, std::milli> duration = std::chrono::high_resolution_clock::now() - _start;
    _state = stopped;

    return duration.count();
}

