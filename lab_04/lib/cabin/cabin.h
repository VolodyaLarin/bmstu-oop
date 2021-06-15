//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_CABIN_H
#define LAB_04_CABIN_H


#include "../doors/doors.h"

RegisterEvent(CabinStoppedEvent);
RegisterEvent(NeedOpenEvent);

class CabinWaitingEvent: public Event {
public:
    int floor = 0;
    enum CabinWaitingEventDirection {up, down};
    CabinWaitingEventDirection direction = down;

    CabinWaitingEvent(): Event(typeid(CabinWaitingEvent).name()) {};
    CabinWaitingEvent(int _floor, CabinWaitingEventDirection dir): CabinWaitingEvent() {
        floor = _floor;
        direction = dir;
    };
};

class Controller;
class CabinWaitingEvent;
class SettingDestinationEvent;

class Cabin: public Subscriber, public Publisher{
private:
    const size_t moving_time = 1000;

    enum CabinState{
        waiting,
        moves,
        stopped
    };
    CabinState _state = waiting;
    Doors doors;
    Timer _timer_floor_moved;
    int _previous_floor = 0;
    int _current_floor = 0;
    int _destination_floor = 0;

public:
    Cabin();

    void subscribe_controller(Controller &controller);
    void on_doors_closed(const Event& event);
    void on_timer_floor_moved(const Event& event);
    void on_setting_destination(const SettingDestinationEvent& event);
    void on_need_open(const NeedOpenEvent& event);
    void on_cabin_stopped(const CabinStoppedEvent& event);
};


#endif //LAB_04_CABIN_H
