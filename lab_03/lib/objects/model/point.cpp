//
// Created by volodya on 01.06.2021.
//

#include "point.h"

const std::shared_ptr<ICoord> &Point::get_coord() const {
    return _coord;
}

void Point::set_coord(const std::shared_ptr<ICoord> &coord) {
    _coord = coord;
}
