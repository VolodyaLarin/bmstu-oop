//
// Created by volodya on 06.06.2021.
//

#include "subscriber.h"

void Subscriber::_add_publisher(IPublisher &publisher) {
    _publishers.insert(&publisher);
}

void Subscriber::remove_publisher(const IPublisher &publisher) {
    for (auto i = _publishers.begin(); i != _publishers.end(); ++i) {
        if (*i == &publisher)
        {
            _publishers.erase(i);
        }
    }
}

Subscriber::~Subscriber() {
    for (auto &publisher: _publishers) {
        publisher->unsubscribe(*this);
    }
}

void Subscriber::lock() {
    pthread_mutex_lock(&mutex);
}

void Subscriber::unlock() {
    pthread_mutex_unlock(&mutex);
}

Subscriber::Subscriber() {
//    pthread_mutex_unlock(&mutex);
}
