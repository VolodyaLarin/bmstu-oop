//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_I_SUBSCRIBER_H
#define LAB_04_I_SUBSCRIBER_H

#include <functional>
#include "event.h"

#define CALLBACK(cb, event) [this](const Event &e){ \
    cb(dynamic_cast<event>(e)); \
}

#define SUBSCRIBE(publisher, event, subscriber, cb) do { \
    ISubscriber::subscribe(publisher, event, subscriber, CALLBACK(cb, const decltype(event)&));                                                          \
}while (0);

typedef std::function<void(const Event&)> callback_t;

class IPublisher;
class ISubscriber {
public:
    virtual ~ISubscriber() = default;
    static void subscribe(IPublisher &publisher,const Event &event, ISubscriber &subscriber, const callback_t& callback);
    virtual void remove_publisher(const IPublisher &) = 0;
    virtual void lock() = 0;
    virtual void unlock() = 0;
private:
    virtual void _add_publisher(IPublisher &) = 0;
};

#endif //LAB_04_I_SUBSCRIBER_H
