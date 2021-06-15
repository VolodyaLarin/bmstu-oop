//
// Created by volodya on 05.06.2021.
//

#include "scale_command.h"

ScaleCommand::ScaleCommand(Scene::iterator &object, const std::shared_ptr<ICoord> &scale):
        TransformCommand(object, ScaleTransformation(scale))
{

}
