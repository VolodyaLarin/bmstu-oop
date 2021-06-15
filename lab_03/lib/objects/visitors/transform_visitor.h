//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_TRANSFORM_VISITOR_H
#define LAB03_TRANSFORM_VISITOR_H


#include "a_visitor.h"
#include "../../utils/transformation.h"
#include "../../managers/transform_manager.h"

class TransformVisitor: public AVisitor{
private:
    Transformation _transformation;
public:
    TransformVisitor(const Transformation &transformation);

    void visitModel(Model &model) override;

    void visitCamera(Camera &camera) override;
};


#endif //LAB03_TRANSFORM_VISITOR_H
