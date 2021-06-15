//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_CAMERA_H
#define LAB03_CAMERA_H

#include <memory>
#include "a_invisible_object.h"
#include "../utils/vector.h"
#include "camera_impl/i_camera_impl.h"

class RenderVisitor;
class TransformVisitor;

class Camera: public AInvisibleObject{
public:
    Camera(const std::shared_ptr<const ICameraImpl> &pimpl);

    void accept(AVisitor &visitor) override;

    std::shared_ptr<ICoord> get_center() override;

private:
    friend RenderVisitor;
    friend TransformVisitor;

    std::optional<std::pair<std::shared_ptr<ICoord2d>, std::shared_ptr<ICoord2d>>> apply(const std::shared_ptr<ICoord> &p1, const std::shared_ptr<ICoord> &p2);

    [[nodiscard]] const Vector &get_vector() const;

    void set_vector(const Vector &vector);

    [[nodiscard]] const std::shared_ptr<const ICameraImpl> &get_pimpl() const;

    void set_pimpl(const std::shared_ptr<const ICameraImpl> &pimpl);
private:
    Vector _vector;
    Transformation _transformation;
    std::shared_ptr<const ICameraImpl> _pimpl;

    void update_transformation();
};


#endif //LAB03_CAMERA_H
