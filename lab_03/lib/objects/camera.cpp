//
// Created by volodya on 01.06.2021.
//
#include "visitors/a_visitor.h"
#include "camera.h"
#include "../utils/coord/coord_solution.h"

void Camera::accept(AVisitor &visitor) {
    visitor.visitCamera(*this);
}

const Vector &Camera::get_vector() const {
    return _vector;
}

void Camera::set_vector(const Vector &vector) {
    _vector = vector;
    update_transformation();
}

[[maybe_unused]] const std::shared_ptr<const ICameraImpl> &Camera::get_pimpl() const {
    return _pimpl;
}

void Camera::set_pimpl(const std::shared_ptr<const ICameraImpl> &pimpl) {
    _pimpl = pimpl;
    update_transformation();
}

std::shared_ptr<ICoord> Camera::get_center() {
    return get_vector().get_begin();
}

Camera::Camera(const std::shared_ptr<const ICameraImpl> &pimpl)
{
    auto creator = CoordSolution().get_creator();
    set_vector(Vector(
            creator->create(0,0,0),
            creator->create(1,0,0)
            ));
    set_pimpl(pimpl);
}

void Camera::update_transformation() {
    if (!_pimpl)
        return;

    _transformation = _pimpl->get_transformation(_vector);
}

std::optional<std::pair<std::shared_ptr<ICoord2d>, std::shared_ptr<ICoord2d>>> Camera::apply(const std::shared_ptr<ICoord> &p1, const std::shared_ptr<ICoord> &p2) {
    auto t1 = _transformation.transform(p1);
    auto t2 = _transformation.transform(p2);

    return get_pimpl()->clip(t1, t2);
}
