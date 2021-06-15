//
// Created by volodya on 01.06.2021.
//

#include <memory>
#include <optional>
#include "../array.h"
#include "i_object.h"
#include "../scene.h"

#ifndef LAB03_COMPOSITE_OBJECT_H
#define LAB03_COMPOSITE_OBJECT_H

#include "../scene.h"

class CompositeObject: public IObject {

public:
    CompositeObject();

    bool is_visible() override;

    bool is_composite() override;

    std::shared_ptr<ICoord> get_center() override;

    void accept(AVisitor &visitor) override;

    iterator begin() override;

    iterator end() override;

    const_iterator cbegin() const override;

    const_iterator cend() const override;

    const_iterator begin() const override;

    const_iterator end() const override;

    iterator add_object(ObjectPtr &object) override;

    void remove_object(ObjectPtr &object) override;

private:
    Array<ObjectPtr> _objects;
};


#endif //LAB03_COMPOSITE_OBJECT_H
