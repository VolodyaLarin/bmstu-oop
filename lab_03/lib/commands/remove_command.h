//
// Created by volodya on 06.06.2021.
//

#ifndef LAB_03_QT_REMOVE_COMMAND_H
#define LAB_03_QT_REMOVE_COMMAND_H


#include "a_scene_command.h"

class RemoveCommand: public ASceneCommand {
private:
    Scene::iterator _object;
public:
    explicit RemoveCommand(const IObjectsPool::iterator &object);

    void execute() override;
};


#endif //LAB_03_QT_REMOVE_COMMAND_H
