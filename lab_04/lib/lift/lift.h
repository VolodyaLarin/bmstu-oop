//
// Created by volodya on 09.06.2021.
//

#ifndef LAB_04_LIFT_H
#define LAB_04_LIFT_H


#include "../cabin/cabin.h"
#include "../controller/controller.h"
#include "../panel/panel.h"
#include "../panel/floor_button.h"

class Lift {
public:
    explicit Lift(int max_floor);

    Panel &get_panel();

    std::vector<FloorButton> &get_buttons();

private:
    Panel _panel;
    std::vector<FloorButton> _buttons;
    Cabin _cabin;
    Controller _controller;
};


#endif //LAB_04_LIFT_H
