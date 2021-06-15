//
// Created by volodya on 04.06.2021.
//

#include "transform_manager_creator.h"

std::shared_ptr<TransformManager> TransformManagerCreator::create() {
    static auto _manager = std::make_shared<TransformManager>();

    return _manager;
}
