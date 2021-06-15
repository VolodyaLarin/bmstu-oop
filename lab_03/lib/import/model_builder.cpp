//
// Created by volodya on 05.06.2021.
//

#include "model_builder.h"
#include "../exception/exceptions.hpp"

void ModelBuilder::build_edge(size_t start, size_t end) {
    auto points_count = _model->points().size();

    if (start >= points_count || end >= points_count)
    {
        time_t t_time;
        time(&t_time);
        throw BuildException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    auto p1 = _model->points().begin() + start;
    auto p2 = _model->points().begin() + end;

    _model->add_edge(Edge(p1, p2));
}

void ModelBuilder::build_point(const std::shared_ptr<ICoord> &coord) {
    Point point;
    point.set_coord(coord);
    _model->add_point(point);
}

void ModelBuilder::reset() {
    _model = std::make_shared<ModelData>();
}

std::shared_ptr<Model> ModelBuilder::get() {
    return std::make_shared<Model>(_model);
}

ModelBuilder::ModelBuilder() {
    ModelBuilder::reset();
}
