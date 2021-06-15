//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_RENDER_MANAGER_H
#define LAB03_RENDER_MANAGER_H


#include <memory>
#include "i_manager.h"
#include "../drawer/i_drawer.h"
#include "../scene.h"
#include "../objects/camera.h"

class RenderManager: public IManager{
private:
public:
    [[nodiscard]] const std::unique_ptr<IDrawer> &get_drawer() const;

    void set_drawer(std::unique_ptr<IDrawer> &&drawer);

    void draw(Scene &scene);

    [[nodiscard]] std::shared_ptr<Camera> get_camera() const;

    void set_camera(const IObjectsPool::iterator &camera);

private:
    std::weak_ptr<Camera> _camera;
    std::unique_ptr<IDrawer> _drawer;
};


#endif //LAB03_RENDER_MANAGER_H
