//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_I_OBJECTS_POOL_H
#define LAB_03_QT_I_OBJECTS_POOL_H

#include "../array.h"

class IObject;
using ObjectPtr = std::shared_ptr<IObject>;

class IObjectsPool {
public:
    using iterator = Array<ObjectPtr>::iterator;
    using const_iterator = Array<ObjectPtr>::const_iterator;

    virtual iterator begin() = 0;

    virtual iterator end() = 0;

    [[nodiscard]] virtual const_iterator cbegin() const = 0;

    [[nodiscard]] virtual const_iterator cend() const = 0;

    [[nodiscard]] virtual const_iterator begin() const = 0;

    [[nodiscard]] virtual const_iterator end() const = 0;

    virtual iterator add_object(ObjectPtr &object) = 0;

    virtual void remove_object(ObjectPtr &object)  = 0;

    virtual ~IObjectsPool() = default;
};


#endif //LAB_03_QT_I_OBJECTS_POOL_H
