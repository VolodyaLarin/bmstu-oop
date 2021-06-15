//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_SET_CAMERA_COMMAND_H
#define LAB_03_QT_SET_CAMERA_COMMAND_H


#include "a_scene_command.h"
#include "../managers/render_manager.h"

class SetCameraCommand: public ICommand {
private:
    std::shared_ptr<RenderManager> _render_manager;
    IObjectsPool::iterator camera;
public:
    explicit SetCameraCommand(const IObjectsPool::iterator &camera, std::shared_ptr<RenderManager> render_manager);
    explicit SetCameraCommand(const IObjectsPool::iterator &camera);

    void execute() override;
};


#endif //LAB_03_QT_SET_CAMERA_COMMAND_H
