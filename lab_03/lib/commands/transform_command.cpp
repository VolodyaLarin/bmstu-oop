//
// Created by volodya on 05.06.2021.
//

#include "transform_command.h"
#include "../managers/creators/transform_manager_creator.h"

TransformCommand::TransformCommand(const IObjectsPool::iterator &object, const Transformation &transformation)
        : _object(object), _transformation(transformation) {

    _transform_manager = TransformManagerCreator().create();
}

void TransformCommand::execute() {
    _transform_manager->transform(**_object, _transformation);
}
