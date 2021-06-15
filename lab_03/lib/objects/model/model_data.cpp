//
// Created by volodya on 04.06.2021.
//

#include "model_data.h"

const Array<Point> &ModelData::get_points() const {
    return _points;
}


const Array<Edge> &ModelData::get_edges() const {
    return _edges;
}

void ModelData::add_point(const Point &point) {
    _points.push_back(point);
}

void ModelData::add_edge(const Edge &edge) {
    _edges.push_back(edge);
}

Array<Point> &ModelData::points() {
    return _points;
}

Array<Edge> &ModelData::edges() {
    return _edges;
}
