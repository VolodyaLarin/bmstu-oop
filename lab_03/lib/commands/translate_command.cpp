//
// Created by volodya on 05.06.2021.
//

#include "translate_command.h"

TranslateCommand::TranslateCommand(const IObjectsPool::iterator &object, const std::shared_ptr<ICoord> &coord)
        : TransformCommand(object, TranslateTransformation(coord)) {}
