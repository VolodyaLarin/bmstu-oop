//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_PUBLISHER_H
#define LAB_04_PUBLISHER_H


#include <map>
#include "i_publisher.h"

class Publisher: public IPublisher {
public:
    void subscribe(const Event &event, ISubscriber &subscriber, const callback_t &callback) override;

    void unsubscribe(const ISubscriber &subscriber) override;

    void unsubscribe(const Event &event, const ISubscriber &subscriber) override;

    void notify(const std::shared_ptr<Event> &) override;

    ~Publisher() override;

private:
    std::map<std::string, std::vector<std::pair<ISubscriber *, std::function<void(const Event &)>>>> _subscribers;
};


#endif //LAB_04_PUBLISHER_H
