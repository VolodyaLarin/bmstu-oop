//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_TRANSFORM_COMMAND_H
#define LAB_03_QT_TRANSFORM_COMMAND_H


#include "i_command.h"
#include "../objects/composite_object.h"
#include "../managers/transform_manager.h"

class TransformCommand: public ICommand {
private:
    IObjectsPool::iterator _object;
    Transformation _transformation;
    std::shared_ptr<TransformManager> _transform_manager;
public:
    TransformCommand(const IObjectsPool::iterator &object, const Transformation &transformation);

    void execute() override;
};


#endif //LAB_03_QT_TRANSFORM_COMMAND_H
