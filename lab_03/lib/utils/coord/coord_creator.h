//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_COORD_CREATOR_H
#define LAB_03_QT_COORD_CREATOR_H


#include "i_coord_creator.h"

class CoordCreator: public ICoordCreator {
public:
    std::shared_ptr<ICoord> create(double x, double y, double z) override;

    std::shared_ptr<ICoord2d> create(double x, double y) override;
};


#endif //LAB_03_QT_COORD_CREATOR_H
