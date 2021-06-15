//
// Created by volodya on 04.06.2021.
//

#include "edge.h"

Edge::Edge(const Array<Point>::iterator &start, const Array<Point>::iterator &anEnd)
: _start(start), _end(anEnd) {}

const Array<Point>::iterator &Edge::get_start() const {
    return _start;
}

void Edge::set_start(const Array<Point>::iterator &start) {
    _start = start;
}

const Array<Point>::iterator &Edge::get_an_end() const {
    return _end;
}

void Edge::set_an_end(const Array<Point>::iterator &anEnd) {
    _end = anEnd;
}
