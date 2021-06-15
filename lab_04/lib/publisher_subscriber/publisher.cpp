//
// Created by volodya on 06.06.2021.
//

#include <thread>
#include <functional>
#include "i_subscriber.h"
#include "publisher.h"

void Publisher::subscribe(const Event &event, ISubscriber &subscriber, const callback_t &callback) {
    _subscribers[event.get_type()].push_back({&subscriber, callback});
}

void Publisher::unsubscribe(const ISubscriber &subscriber){
    for (auto &event: _subscribers) {
        for (auto item = event.second.begin(); item != event.second.end(); ++item) {
            if (item->first == &subscriber)
            {
                event.second.erase(item);
            }
        }
    }
}

void Publisher::unsubscribe(const Event &event, const ISubscriber &subscriber) {
    auto &subscribers = _subscribers[event.get_type()];
    for (auto item = subscribers.begin(); item != subscribers.end(); ++item) {
        if (item->first == &subscriber)
        {
            subscribers.erase(item);
        }
    }
}

Publisher::~Publisher() {
    for (auto &event: _subscribers) {
        for (auto& subscriber: event.second) {
            subscriber.first->remove_publisher(*this);
        }
    }
}

void Publisher::notify(const std::shared_ptr<Event> &event) {
    auto &subscribers = _subscribers[event->get_type()];
    for (auto &item: subscribers) {
        std::thread([item](const std::shared_ptr<Event> &event) {
            item.first->lock();
            item.second(*event);
            item.first->unlock();
        }, event).detach();
    }
}
