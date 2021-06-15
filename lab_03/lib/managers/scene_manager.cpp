//
// Created by volodya on 02.06.2021.
//

#include "scene_manager.h"

Scene::iterator SceneManager::add_object(ObjectPtr &object) {
    return _scene.add_object(object);
}

void SceneManager::remove_object(ObjectPtr &object) {
    _scene.remove_object(object);
}

Scene &SceneManager::get_scene() {
    return _scene;
}
