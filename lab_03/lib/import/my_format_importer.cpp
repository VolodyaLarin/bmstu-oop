//
// Created by volodya on 05.06.2021.
//

#include <iostream>

#include "my_format_importer.h"
#include "model_director.h"
#include "model_builder.h"
#include "../exception/exceptions.hpp"
#include "../utils/coord/coord_solution.h"

std::shared_ptr<Model> MyFormatImporter::import(std::istream &istream) {
    ModelDirector director;
    director.set_builder(std::make_shared<ModelBuilder>());

    auto coords = _import_points(istream);
    auto edges = _import_edges(istream);

    return director.build(coords, edges);
}

Array<std::shared_ptr<ICoord>> MyFormatImporter::_import_points(std::istream &istream) const {
    auto creator = CoordSolution().get_creator();

    Array<std::shared_ptr<ICoord>> coords= {};
    size_t size_points;
    istream >> size_points;
    if (istream.eof())
    {
        time_t t_time;
        time(&t_time);
        throw InvalidSourceException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    for (size_t i = 0; i < size_points; ++i)
    {
        double x, y, z;
        istream >> x >> y >> z;
        if (istream.eof())
        {
            time_t t_time;
            time(&t_time);
            throw InvalidSourceException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        coords.push_back(creator->create(x, y, z));
    }

    return coords;
}

Array<std::pair<size_t, size_t>> MyFormatImporter::_import_edges(std::istream &istream) const {
    Array<std::pair<size_t, size_t>> edges = {};
    size_t size_edges;
    istream >> size_edges;
    if (istream.eof())
    {
        time_t t_time;
        time(&t_time);
        throw InvalidSourceException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    for (size_t i = 0; i < size_edges; ++i)
    {
        size_t p1, p2;
        istream >> p1 >> p2;
        if (istream.eof())
        {
            time_t t_time;
            time(&t_time);
            throw InvalidSourceException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
        edges.push_back({p1, p2});
    }
    return edges;
}
