//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_RENDER_COMMAND_H
#define LAB03_RENDER_COMMAND_H


#include "a_scene_command.h"
#include "../managers/render_manager.h"

class RenderCommand: public ASceneCommand{
private:
    std::shared_ptr<RenderManager> _render_manager;
public:
    RenderCommand();
    void execute() override;
};


#endif //LAB03_RENDER_COMMAND_H
