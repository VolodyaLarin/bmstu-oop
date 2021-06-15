//
// Created by volodya on 04.06.2021.
//

#include <algorithm>
#include "model.h"
#include "visitors/a_visitor.h"
#include "../utils/coord/coord_solution.h"

void Model::accept(AVisitor &visitor) {
    visitor.visitModel(*this);
}


std::shared_ptr<ModelData> &Model::data() {
    return _data;
}

std::shared_ptr<ICoord> Model::get_center() {
    auto cmp_x = [](const Point& p1, const Point& p2) -> bool {
        return p1.get_coord()->get_x() < p2.get_coord()->get_x();
    };
    auto cmp_y = [](const Point& p1, const Point& p2) -> bool {
        return p1.get_coord()->get_y() < p2.get_coord()->get_y();
    };
    auto cmp_z = [](const Point& p1, const Point& p2) -> bool {
        return p1.get_coord()->get_z() < p2.get_coord()->get_z();
    };

    auto max_x = std::max_element(_data->get_points().begin(), _data->get_points().end(), cmp_x)
            ->get_coord()->get_x();
    auto min_x = std::min_element(_data->get_points().begin(), _data->get_points().end(), cmp_x)
            ->get_coord()->get_x();

    auto max_y = std::max_element(_data->get_points().begin(), _data->get_points().end(), cmp_y)
            ->get_coord()->get_y();
    auto min_y = std::min_element(_data->get_points().begin(), _data->get_points().end(), cmp_y)
            ->get_coord()->get_y();

    auto max_z = std::max_element(_data->get_points().begin(), _data->get_points().end(), cmp_z)
            ->get_coord()->get_z();
    auto min_z = std::min_element(_data->get_points().begin(), _data->get_points().end(), cmp_z)
            ->get_coord()->get_z();

    return CoordSolution().get_creator()->create(
            (max_x + min_x) / 2, (max_y + min_y) / 2, (max_z + min_z) / 2
    );
}

Model::Model(const std::shared_ptr<ModelData> &data) {
    _data = data;
}
