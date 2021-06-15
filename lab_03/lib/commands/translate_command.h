//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_TRANSLATE_COMMAND_H
#define LAB_03_QT_TRANSLATE_COMMAND_H


#include "transform_command.h"

class TranslateCommand: public TransformCommand {
public:
    TranslateCommand(const IObjectsPool::iterator &object, const std::shared_ptr<ICoord> &coord);
};


#endif //LAB_03_QT_TRANSLATE_COMMAND_H
