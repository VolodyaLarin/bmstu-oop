//
// Created by volodya on 05.06.2021.
//

#include "a_scene_command.h"
#include "../managers/creators/scene_manager_creator.h"

ASceneCommand::ASceneCommand() {
    _scene_manager = SceneManagerCreator().create();
}
