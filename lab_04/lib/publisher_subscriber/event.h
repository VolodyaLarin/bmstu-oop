//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_04_EVENT_CPP_H
#define LAB_04_EVENT_CPP_H

#include <string>

#define RegisterEvent(Name) class Name: public Event { \
public:\
    Name(): Event(typeid(Name).name()){}; \
}

class Event {
protected:
    std::string _type;
public:
    explicit Event(const std::string &type);

    [[nodiscard]] virtual const std::string &get_type() const;
};

#endif //LAB_04_EVENT_CPP_H
