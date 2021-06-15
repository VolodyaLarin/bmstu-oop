//
// Created by volodya on 09.06.2021.
//

#ifndef LAB_04_PANEL_H
#define LAB_04_PANEL_H


#include "../publisher_subscriber/publisher.h"

class Panel: public Publisher {
public:
    Panel(int maxFloors);

    void push_button(int floor);
private:
    int max_floors;
};


#endif //LAB_04_PANEL_H
