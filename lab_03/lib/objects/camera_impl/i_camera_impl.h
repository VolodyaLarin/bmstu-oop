//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_I_CAMERA_IMPL_H
#define LAB03_I_CAMERA_IMPL_H

#include <optional>
#include <memory>

#include "../../utils/vector.h"
#include "../../utils/coord/coord_2d.h"
#include "../../utils/transformation.h"

class ICameraImpl {
public:
    virtual Transformation get_transformation(const Vector &vector) const = 0;
    virtual std::optional<std::pair<std::shared_ptr<ICoord2d>, std::shared_ptr<ICoord2d>>> clip(const std::shared_ptr<ICoord> &p1, const std::shared_ptr<ICoord> &p2) const = 0;
    virtual ~ICameraImpl() = default;
};


#endif //LAB03_I_CAMERA_IMPL_H
