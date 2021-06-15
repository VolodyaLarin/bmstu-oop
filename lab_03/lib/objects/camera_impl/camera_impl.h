//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_CAMERA_IMPL_H
#define LAB03_CAMERA_IMPL_H

#define CAMERA_K 0.001

#include "i_camera_impl.h"
#include "../../utils/vector.h"
#include "../../utils/transformation.h"

class CameraImpl: public ICameraImpl{
public:
    [[nodiscard]] Transformation get_transformation(const Vector &vector) const override;
    [[nodiscard]] std::optional<std::pair<std::shared_ptr<ICoord2d>, std::shared_ptr<ICoord2d>>> clip(const std::shared_ptr<ICoord> &p1, const std::shared_ptr<ICoord> &p2) const override;

};


#endif //LAB03_CAMERA_IMPL_H
