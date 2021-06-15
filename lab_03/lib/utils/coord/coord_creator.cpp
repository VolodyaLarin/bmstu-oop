//
// Created by volodya on 10.06.2021.
//

#include "coord_creator.h"
#include "coord.h"

std::shared_ptr<ICoord> CoordCreator::create(double x, double y, double z) {
    return std::make_shared<Coord>(x, y, z);
}

std::shared_ptr<ICoord2d> CoordCreator::create(double x, double y) {
    return std::make_shared<Coord2d>(x, y);
}
