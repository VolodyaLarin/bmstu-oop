//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_A_VISIBLE_OBJECT_H
#define LAB03_A_VISIBLE_OBJECT_H


#include "i_object.h"
#include "empty_objects_pool.h"

class AVisibleObject: public IObject{
public:
    bool is_visible() override;

    bool is_composite() override;
};


#endif //LAB03_A_VISIBLE_OBJECT_H
