//
// Created by volodya on 02.06.2021.
//

#include "transform_manager.h"
#include "../objects/visitors/transform_visitor.h"
void TransformManager::transform(IObject & object, const Transformation & transformation) {
    TransformVisitor visitor(transformation);

    object.accept(visitor);
}
