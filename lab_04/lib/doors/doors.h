//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_DOORS_H
#define LAB_04_DOORS_H

#include "../publisher_subscriber/subscriber.h"
#include "../publisher_subscriber/publisher.h"
#include "../timer/timer.h"

class Cabin;

RegisterEvent(DoorsClosedEvent);

class Doors: public Publisher, public Subscriber {
private:
    const size_t action_time = 1000;
    const size_t waiting_time = 3000;

    enum DoorsState {
        opened,
        closed,
        opening,
        closing,
    };
    DoorsState _state = DoorsState::closed;

    Timer _timer_close;
    Timer _timer_open;
    Timer _timer_waiting;
public:
    explicit Doors(Cabin &);

private:
    void on_cabin_stopped(const Event& event);
    void on_timer_close(const Event& event);
    void on_timer_open(const Event& event);
    void on_timer_waiting(const Event& event);
};


#endif //LAB_04_DOORS_H
