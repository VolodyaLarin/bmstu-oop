//
// Created by volodya on 05.06.2021.
//

#include "rotate_command.h"

RotateCommand::RotateCommand(Scene::iterator &object, const std::shared_ptr<ICoord> &rotation)
: TransformCommand(object, RotateTransformation(rotation)){

}
