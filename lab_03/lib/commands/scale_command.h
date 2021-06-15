//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_SCALE_COMMAND_H
#define LAB_03_QT_SCALE_COMMAND_H

#include "../scene.h"
#include "transform_command.h"

class ScaleCommand: public TransformCommand{
public:
    ScaleCommand(Scene::iterator& object, const std::shared_ptr<ICoord>& scale);
};


#endif //LAB_03_QT_SCALE_COMMAND_H
