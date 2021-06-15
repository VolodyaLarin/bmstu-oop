//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_A_SCENE_COMMAND_H
#define LAB03_A_SCENE_COMMAND_H


#include "i_command.h"
#include "../managers/scene_manager.h"

class ASceneCommand: public ICommand{
protected:
    std::shared_ptr<SceneManager> _scene_manager;
public:
    ASceneCommand();
};


#endif //LAB03_A_SCENE_COMMAND_H
