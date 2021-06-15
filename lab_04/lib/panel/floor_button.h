//
// Created by volodya on 09.06.2021.
//

#ifndef LAB_04_FLOOR_BUTTON_H
#define LAB_04_FLOOR_BUTTON_H


#include "../publisher_subscriber/publisher.h"

class FloorButton: public Publisher{
public:
    FloorButton() = default;
    explicit FloorButton(int floor);
    void push();

    int get_floor() const;

    void set_floor(int floor);

private:
    int _floor = 0;
};


#endif //LAB_04_FLOOR_BUTTON_H
