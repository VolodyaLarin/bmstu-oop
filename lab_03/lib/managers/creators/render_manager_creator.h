//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_RENDER_MANAGER_CREATOR_H
#define LAB03_RENDER_MANAGER_CREATOR_H


#include <memory>
#include "i_manager_creator.h"
#include "../render_manager.h"

class RenderManagerCreator: public IManagerCreator{
public:
    std::shared_ptr<RenderManager> create();
};


#endif //LAB03_RENDER_MANAGER_CREATOR_H
