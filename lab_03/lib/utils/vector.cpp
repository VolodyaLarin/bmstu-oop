//
// Created by volodya on 01.06.2021.
//

#include <cmath>

#include "vector.h"
#include "coord/coord_solution.h"

Vector::Vector(const std::shared_ptr<ICoord> &begin, const std::shared_ptr<ICoord> &end) : _begin(begin), _end(end) {}

const std::shared_ptr<ICoord> &Vector::get_begin() const {
    return _begin;
}

void Vector::set_begin(const std::shared_ptr<ICoord> &begin) {
    _begin = begin;
}

const std::shared_ptr<ICoord> &Vector::get_end() const {
    return _end;
}

void Vector::set_end(const std::shared_ptr<ICoord> &end) {
    _end = end;
}

std::shared_ptr<ICoord> Vector::get_rotation() const {
    auto creator = CoordSolution().get_creator();

    return creator->create(
            atan2(get_dy(), get_dz()),
            atan2(get_dz(), get_dx()),
            atan2(get_dy(), get_dx())
            );
}

double Vector::get_dx() const{
    return _end->get_x() - _begin->get_x();
}

double Vector::get_dy() const{
    return _end->get_y() - _begin->get_y();
}

double Vector::get_dz() const{
    return _end->get_z() - _begin->get_z();
}


double Vector::get_size() const {
    auto dx = get_dx();
    auto dy = get_dy();
    auto dz = get_dz();

    return sqrt(dx*dx + dy*dy + dz*dz);
}

std::shared_ptr<ICoord> Vector::get_d() const {
    auto creator = CoordSolution().get_creator();

    return creator->create(get_dx(), get_dy(), get_dz());
}
