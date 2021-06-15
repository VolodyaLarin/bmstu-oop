//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_TIMER_H
#define LAB_04_TIMER_H

#include <chrono>

#include "../publisher_subscriber/event.h"
#include "../publisher_subscriber/publisher.h"

RegisterEvent(TimerEvent);

class Timer: public Publisher {
private:
    enum TimerState {
        waiting,
        stopped
    };
    std::chrono::high_resolution_clock::time_point _start;

    TimerState _state = stopped;
public:
    void start(size_t ms);
    size_t stop();
};


#endif //LAB_04_TIMER_H
