//
// Created by volodya on 01.06.2021.
//

#include "visitors/a_visitor.h"
#include "composite_object.h"
#include "i_object.h"
#include "../utils/coord/coord_solution.h"

bool CompositeObject::is_visible() {
    return true;
}

void CompositeObject::accept(AVisitor &visitor) {
    visitor.visitComposite(*this);
}

CompositeObject::CompositeObject() = default;

std::shared_ptr<ICoord> CompositeObject::get_center() {
    return CoordSolution().get_creator()->create(0,0,0);
}

bool CompositeObject::is_composite() {
    return true;
}


IObjectsPool::iterator CompositeObject::begin() {
    return _objects.begin();
}

IObjectsPool::iterator CompositeObject::end() {
    return _objects.end();
}

IObjectsPool::const_iterator CompositeObject::cbegin() const{
    return _objects.cbegin();
}

IObjectsPool::const_iterator CompositeObject::cend() const{
    return _objects.cend();
}

IObjectsPool::const_iterator CompositeObject::begin() const {
    return _objects.begin();
}

IObjectsPool::const_iterator CompositeObject::end() const {
    return _objects.end();
}

IObjectsPool::iterator CompositeObject::add_object(ObjectPtr &object) {
    _objects.push_back(object);
    return _objects.begin() + (_objects.size() - 1);
}

void CompositeObject::remove_object(ObjectPtr &object) {

    for (auto pi = _objects.begin(); pi != _objects.end(); ++pi) {
        if (*pi == object)
        {
            _objects.erase(pi);
            return;
        }
    }
}
