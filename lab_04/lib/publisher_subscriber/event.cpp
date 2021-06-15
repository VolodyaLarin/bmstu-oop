//
// Created by volodya on 09.06.2021.
//


#include "event.h"

const std::string &Event::get_type() const {
    return _type;
}

Event::Event(const std::string &type) : _type(type) {}
