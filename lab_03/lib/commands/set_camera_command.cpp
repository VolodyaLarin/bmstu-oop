//
// Created by volodya on 05.06.2021.
//

#include "set_camera_command.h"
#include "../managers/creators/render_manager_creator.h"

void SetCameraCommand::execute() {
    _render_manager->set_camera(camera);
}


SetCameraCommand::SetCameraCommand(const IObjectsPool::iterator &camera,
                                   std::shared_ptr<RenderManager> render_manager): _render_manager(render_manager), camera(camera) {

}







SetCameraCommand::SetCameraCommand(const IObjectsPool::iterator &camera) : SetCameraCommand(camera, RenderManagerCreator().create()) {}

