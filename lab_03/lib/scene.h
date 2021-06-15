//
// Created by volodya on 07.06.2021.
//

#ifndef LAB_03_QT_SCENE_H
#define LAB_03_QT_SCENE_H

#include "objects/i_objects_pool.h"
#include <memory>
#include <optional>


class Scene: public IObjectsPool {
public:
    iterator begin() override;

    iterator end() override;

    [[nodiscard]] const_iterator cbegin() const override;

    [[nodiscard]] const_iterator cend() const override;

    [[nodiscard]] const_iterator begin() const override;

    [[nodiscard]] const_iterator end() const override;

    iterator add_object(ObjectPtr &object) override;

    void remove_object(ObjectPtr &object) override;

private:
    Array<ObjectPtr> _objects;
};


#endif //LAB_03_QT_SCENE_H
