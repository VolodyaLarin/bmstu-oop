//
// Created by volodya on 06.06.2021.
//


#include "i_subscriber.h"
#include "i_publisher.h"
#include <functional>

void ISubscriber::subscribe(IPublisher &publisher, const Event &event, ISubscriber &subscriber,
                            const callback_t &callback) {
    subscriber._add_publisher(publisher);
    publisher.subscribe(event, subscriber, callback);
}
