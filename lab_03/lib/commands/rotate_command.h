//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_ROTATE_COMMAND_H
#define LAB_03_QT_ROTATE_COMMAND_H

#include "../scene.h"
#include "transform_command.h"

class RotateCommand: public TransformCommand {
public:
    RotateCommand(Scene::iterator& object, const std::shared_ptr<ICoord> &rotation);
};


#endif //LAB_03_QT_ROTATE_COMMAND_H
