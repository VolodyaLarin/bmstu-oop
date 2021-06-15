//
// Created by volodya on 02.06.2021.
//

#ifndef LAB03_SCENE_MANAGER_H
#define LAB03_SCENE_MANAGER_H


#include "i_manager.h"
#include "../scene.h"


class SceneManager: public IManager{
    Scene _scene;
public:
    Scene::iterator add_object(ObjectPtr &object);
    void remove_object(ObjectPtr &object);

    Scene &get_scene();


};


#endif //LAB03_SCENE_MANAGER_H
