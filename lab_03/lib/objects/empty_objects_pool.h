//
// Created by volodya on 07.06.2021.
//

#ifndef LAB_03_QT_EMPTY_OBJECTS_POOL_H
#define LAB_03_QT_EMPTY_OBJECTS_POOL_H


#include <memory>
#include <optional>
#include "i_object.h"
#include "i_objects_pool.h"


class EmptyObjectsPool: public IObjectsPool {
public:
    iterator begin() override {
        return iterator();
    };

    iterator end() override {
        return iterator();
    };

    [[nodiscard]] const_iterator cbegin() const override {
        return iterator();
    };

    [[nodiscard]] const_iterator cend() const override
    {
        return iterator();
    };

    [[nodiscard]] const_iterator begin() const override {
        return iterator();
    };

    [[nodiscard]] const_iterator end() const override {
        return iterator();
    };

    iterator add_object(ObjectPtr &object) override {
        return iterator();
    };

    void remove_object(ObjectPtr &object) override {};
};


#endif //LAB_03_QT_EMPTY_OBJECTS_POOL_H
