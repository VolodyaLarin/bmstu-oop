//
// Created by volodya on 01.06.2021.
//

#include "camera_impl.h"
#include "../../utils/coord/coord_solution.h"

Transformation CameraImpl::get_transformation(const Vector &vector) const {
    auto creator = CoordSolution().get_creator();

    auto size = vector.get_size();

    Transformation transform = TranslateTransformation(vector.get_begin())
            .join(RotateTransformation(vector.get_rotation()))
            .join(ScaleTransformation(creator->create(size,size,size)))
            .join(PerspectiveTransformation(CAMERA_K));
    return transform;
}

std::optional<std::pair<std::shared_ptr<ICoord2d>, std::shared_ptr<ICoord2d>>>
CameraImpl::clip(const std::shared_ptr<ICoord> &t1, const std::shared_ptr<ICoord> &t2) const {
    auto creator = CoordSolution().get_creator();

    if (t1->get_z() < 0 && t2->get_z() < 0)
        return std::nullopt;

    if (t1->get_z() >= 0 && t2->get_z() >= 0)
    {
        return std::pair(
                creator->create(t1->get_x(), t1->get_y()),
                creator->create(t2->get_x(), t2->get_y())
        );
    }

    auto vec = Vector(t1, t2).get_d();

    if (vec->get_z() == 0)
    {
        return std::pair(
                creator->create(t1->get_x(), t1->get_y()),
                creator->create(t2->get_x(), t2->get_y())
        );
    }

    double x0 = t1->get_x(), a = vec->get_x(),
            y0 = t1->get_y(), b = vec->get_y(),
            z0 = t1->get_z(), c = vec->get_z();

    double x = x0 - a * z0 / c;
    double y = y0 - b * z0 / c;

    auto other = t2;

    if (c < 0) {
        other = t1;
    }

    return std::pair(
            creator->create(x, y),
            creator->create(other->get_x(), other->get_y())
    );
}
