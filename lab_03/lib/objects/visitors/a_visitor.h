//
// Created by volodya on 02.06.2021.
//

#ifndef LAB03_I_visitor_H
#define LAB03_I_visitor_H


#include "../camera.h"
#include "../composite_object.h"
#include "../model.h"

class AVisitor {
public:
    virtual void visitModel(Model &model) = 0;
    virtual void visitCamera(Camera &camera) = 0;
    virtual void visitComposite(CompositeObject &composite);
};


#endif //LAB03_I_visitor_H
