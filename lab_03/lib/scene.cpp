//
// Created by volodya on 07.06.2021.
//

#include "objects/visitors/a_visitor.h"
#include "scene.h"

Scene::iterator Scene::begin() {
    return _objects.begin();
}

Scene::iterator Scene::end() {
    return _objects.end();
}

Scene::const_iterator Scene::cbegin() const{
    return _objects.cbegin();
}

Scene::const_iterator Scene::cend() const{
    return _objects.cend();
}

Scene::const_iterator Scene::begin() const {
    return _objects.begin();
}

Scene::const_iterator Scene::end() const {
    return _objects.end();
}

Scene::iterator Scene::add_object(ObjectPtr &object) {
    _objects.push_back(object);
    return _objects.begin() + (_objects.size() - 1);
}

void Scene::remove_object(ObjectPtr &object) {

    for (auto pi = _objects.begin(); pi != _objects.end(); ++pi) {
        if (*pi == object)
        {
            _objects.erase(pi);
            return;
        }
    }
}