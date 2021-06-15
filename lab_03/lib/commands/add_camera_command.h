//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_ADD_CAMERA_COMMAND_H
#define LAB_03_QT_ADD_CAMERA_COMMAND_H


#include "a_scene_command.h"
#include "../managers/render_manager.h"

class AddCameraCommand: public ASceneCommand{
private:
    std::shared_ptr<RenderManager> _render_manager;
public:

    explicit AddCameraCommand(std::shared_ptr<RenderManager> render_manager);
    AddCameraCommand();

    void execute() override;
};


#endif //LAB_03_QT_ADD_CAMERA_COMMAND_H
