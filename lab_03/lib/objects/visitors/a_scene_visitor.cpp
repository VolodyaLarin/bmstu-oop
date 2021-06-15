//
// Created by volodya on 04.06.2021.
//

#include "a_scene_visitor.h"
#include "../../managers/creators/scene_manager_creator.h"

ASceneVisitor::ASceneVisitor(): _scene_manager(
        ([]()->std::shared_ptr<SceneManager> {return SceneManagerCreator().create();})()
        ) {

}
