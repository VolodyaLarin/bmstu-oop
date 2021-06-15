//
// Created by volodya on 02.06.2021.
//

#ifndef LAB03_TRANSFORM_MANAGER_H
#define LAB03_TRANSFORM_MANAGER_H


#include "i_manager.h"
#include "../utils/transformation.h"
#include "../objects/i_object.h"

class TransformManager: public IManager {
public:
    void transform(IObject &, const Transformation&);
};


#endif //LAB03_TRANSFORM_MANAGER_H
