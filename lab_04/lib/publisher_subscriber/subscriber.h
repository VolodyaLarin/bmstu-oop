//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_SUBSCRIBER_H
#define LAB_04_SUBSCRIBER_H


#include <set>
#include "i_subscriber.h"
#include "i_publisher.h"

class Subscriber: public ISubscriber{
public:
    Subscriber();
    void remove_publisher(const IPublisher &publisher) override;
    ~Subscriber() override;

    void lock() override;

    void unlock() override;

private:
    void _add_publisher(IPublisher &publisher) override;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    std::set<IPublisher *> _publishers;
};


#endif //LAB_04_SUBSCRIBER_H
