//
// Created by volodya on 01.06.2021.
//

#include "coord.h"

Coord::Coord(double x, double y, double z): _x(x), _y(y), _z(z) {}

double Coord::get_x() const {
    return _x;
}

void Coord::set_x(double x) {
    _x = x;
}

double Coord::get_y() const {
    return _y;
}

void Coord::set_y(double y) {
    _y = y;
}

double Coord::get_z() const {
    return _z;
}

void Coord::set_z(double z) {
    _z = z;
}

std::shared_ptr<ICoord> Coord::inverse() const {
    return std::make_shared<Coord>(-get_x(), -get_y(), -get_z());
}

