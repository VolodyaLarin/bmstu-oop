//
// Created by volodya on 01.06.2021.
//

#include "coord_2d.h"

Coord2d::Coord2d(double x, double y) : _x(x), _y(y) {}

double Coord2d::get_x() const {
    return _x;
}

void Coord2d::set_x(double x) {
    _x = x;
}

double Coord2d::get_y() const {
    return _y;
}

void Coord2d::set_y(double y) {
    _y = y;
}
