//
// Created by volodya on 09.06.2021.
//

#include "lift.h"

Panel &Lift::get_panel() {
    return _panel;
}

std::vector<FloorButton> &Lift::get_buttons() {
    return _buttons;
}

Lift::Lift(int floors): _buttons(floors), _panel(floors),
    _controller(_cabin, [this]() -> std::vector<IPublisher *>{
        std::vector<IPublisher *> publishers;
        for (auto &p: _buttons) {
            publishers.push_back(&p);
        }
        publishers.push_back(&_panel);
        return publishers;
}(), floors)
{
    for (int i = 0; i < floors; ++i) {
        _buttons[i].set_floor(i);
    }
    _cabin.subscribe_controller(_controller);
}
