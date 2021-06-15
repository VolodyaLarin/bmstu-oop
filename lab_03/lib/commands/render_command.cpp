//
// Created by volodya on 05.06.2021.
//

#include "render_command.h"
#include "../managers/creators/render_manager_creator.h"

RenderCommand::RenderCommand() {
    _render_manager = RenderManagerCreator().create();
}

void RenderCommand::execute() {
    _render_manager->draw(_scene_manager->get_scene());
}


