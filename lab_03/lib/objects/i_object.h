//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_I_OBJECT_H
#define LAB03_I_OBJECT_H


#include <optional>
#include "../utils/coord/coord.h"
#include "empty_objects_pool.h"

class AVisitor;
class CompositeObject;

class IObject: public EmptyObjectsPool {
public:
    virtual bool is_visible() = 0;
    virtual bool is_composite() = 0;
    virtual void accept(AVisitor &) = 0;
    virtual std::shared_ptr<ICoord> get_center() = 0;
    virtual ~IObject() = default;
};

#include "composite_object.h"

#endif //LAB03_I_OBJECT_H
