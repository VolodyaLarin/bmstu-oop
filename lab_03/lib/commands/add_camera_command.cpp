//
// Created by volodya on 05.06.2021.
//

#include "add_camera_command.h"

#include <utility>
#include "../objects/camera.h"
#include "../objects/camera_impl/camera_impl.h"
#include "../managers/creators/render_manager_creator.h"

void AddCameraCommand::execute() {
    auto camera = std::make_shared<Camera>(std::make_shared<CameraImpl>());

    ObjectPtr object = camera;

    auto iterator = _scene_manager->add_object(object);
    _render_manager->set_camera(iterator);
}


AddCameraCommand::AddCameraCommand(std::shared_ptr<RenderManager> render_manager): _render_manager(std::move(render_manager)) {

}











AddCameraCommand::AddCameraCommand() : AddCameraCommand(RenderManagerCreator().create()) {}

