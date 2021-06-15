//
// Created by volodya on 04.06.2021.
//

#include "render_manager.h"
#include "../objects/visitors/render_visitor.h"
#include "../exception/exceptions.hpp"

const std::unique_ptr<IDrawer> &RenderManager::get_drawer() const {
    return _drawer;
}

void RenderManager::set_drawer(std::unique_ptr<IDrawer> &&drawer) {
    _drawer = std::move(drawer);
}

void RenderManager::draw(Scene &scene) {
    _drawer->clear();

    RenderVisitor visitor;

    for (auto &object: scene) {
        object->accept(visitor);
    }

    _drawer->apply();
}

std::shared_ptr<Camera> RenderManager::get_camera() const {
    if (_camera.expired() || _camera.lock() == nullptr){
        time_t t_time;
        time(&t_time);
        throw NoCameraException(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return _camera.lock();
}

void RenderManager::set_camera(const IObjectsPool::iterator &camera) {
    _camera = std::dynamic_pointer_cast<Camera>(*camera);
}
