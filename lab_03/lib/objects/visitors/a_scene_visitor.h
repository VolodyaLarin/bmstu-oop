//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_A_SCENE_VISITOR_H
#define LAB03_A_SCENE_VISITOR_H


#include "a_visitor.h"
#include "../../managers/scene_manager.h"

class ASceneVisitor: public AVisitor{
protected:
    std::shared_ptr<SceneManager> _scene_manager;
public:
    ASceneVisitor();
};


#endif //LAB03_A_SCENE_VISITOR_H
