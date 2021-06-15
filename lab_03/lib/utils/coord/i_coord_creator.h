//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_I_COORD_CREATOR_H
#define LAB_03_QT_I_COORD_CREATOR_H


#include "i_coord.h"
#include "i_coord_2d.h"

class ICoordCreator {
public:
    virtual std::shared_ptr<ICoord2d> create(double x, double y) = 0;

    virtual std::shared_ptr<ICoord> create(double x, double y, double z) = 0;
};


#endif //LAB_03_QT_I_COORD_CREATOR_H
