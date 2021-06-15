//
// Created by volodya on 05.06.2021.
//

#include "model_director.h"
#include "../exception/exceptions.hpp"

void ModelDirector::set_builder(const std::shared_ptr<IModelBuilder> &builder) {
    _builder = builder;
}

std::shared_ptr<Model> ModelDirector::build(const Array<std::shared_ptr<ICoord>> &points, const Array<std::pair<size_t, size_t>> &edges) {
    if (points.size() <= 0 || edges.size() <= 0)
    {
        time_t t_time;
        time(&t_time);
        throw BuildException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    _builder->reset();

    for (const auto &point: points) {
        _builder->build_point(point);
    }

    for (const auto &edge: edges) {
        _builder->build_edge(edge.first, edge.second);
    }

    return _builder->get();
}
