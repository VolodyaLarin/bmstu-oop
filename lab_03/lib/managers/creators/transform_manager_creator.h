//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_SCENE_MANAGER_CREATOR_H
#define LAB03_SCENE_MANAGER_CREATOR_H


#include "i_manager_creator.h"
#include "../transform_manager.h"

class TransformManagerCreator: public IManagerCreator {
public:
    virtual std::shared_ptr<TransformManager> create();
};


#endif //LAB03_SCENE_MANAGER_CREATOR_H
