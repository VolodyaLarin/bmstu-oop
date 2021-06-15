//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_I_DRAWER_H
#define LAB03_I_DRAWER_H


#include "../utils/coord/coord_2d.h"

class IDrawer {
public:
    virtual void apply() = 0;

    virtual void clear() = 0;

    virtual void draw_line(const std::shared_ptr<ICoord2d>& p1,const std::shared_ptr<ICoord2d>& p2) = 0;

    virtual void resize(int w, int h) = 0;
};


#endif //LAB03_I_DRAWER_H
