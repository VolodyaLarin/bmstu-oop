//
// Created by volodya on 05.06.2021.
//

#include "render_manager_creator.h"

std::shared_ptr<RenderManager> RenderManagerCreator::create() {
    static auto _manager = std::make_shared<RenderManager>();
    return _manager;
}
