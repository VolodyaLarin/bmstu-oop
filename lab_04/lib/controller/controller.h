//
// Created by volodya on 07.06.2021.
//

#ifndef LAB_04_CONTROLLER_H
#define LAB_04_CONTROLLER_H


#include "../publisher_subscriber/publisher.h"
#include "../publisher_subscriber/subscriber.h"
#include "../cabin/cabin.h"



class SettingDestinationEvent: public Event {
public:
    int floor = 0;
    SettingDestinationEvent(): Event(typeid(SettingDestinationEvent).name()) {};
    explicit SettingDestinationEvent(int _floor): SettingDestinationEvent() {
        floor = _floor;
    };
};

class PushFloorButtonEvent: public Event {
public:
    int floor = 0;
    PushFloorButtonEvent(): Event(typeid(PushFloorButtonEvent).name()) {};
    explicit PushFloorButtonEvent(int _floor): PushFloorButtonEvent() {
        floor = _floor;
    };
};


class Controller: public Publisher, public Subscriber {
public:
    Controller(Cabin &cabin, const std::vector<IPublisher *> &publishers, int floors);
    void on_cabin_waiting(const CabinWaitingEvent &e);
    void on_pushing_button(const PushFloorButtonEvent&);
private:
    enum ControllerState {
        waiting,
        busy
    };
    ControllerState _state = waiting;
    std::vector<bool> _floors;
    int _destination_floor = 0;
};


#endif //LAB_04_CONTROLLER_H
