//
// Created by volodya on 04.06.2021.
//


#include "scene_manager_creator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::create() {
    static auto _manager = std::make_shared<SceneManager>();

    return _manager;
}