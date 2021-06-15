//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_I_PUBLISHER_H
#define LAB_04_I_PUBLISHER_H


#include <functional>
#include <memory>
#include "event.h"
#include "i_subscriber.h"

class IPublisher {
public:
    virtual void subscribe(const Event &, ISubscriber &subscriber, const callback_t& callback) = 0;
    virtual void unsubscribe(const ISubscriber &subscriber) = 0;
    virtual void unsubscribe(const Event &, const ISubscriber &subscriber) = 0;
    virtual void notify(const std::shared_ptr<Event> &) = 0;
    virtual ~IPublisher() = default;
};


#endif //LAB_04_I_PUBLISHER_H
