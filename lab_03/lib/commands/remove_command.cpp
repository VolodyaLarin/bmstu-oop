//
// Created by volodya on 06.06.2021.
//

#include "remove_command.h"

RemoveCommand::RemoveCommand(const IObjectsPool::iterator &object) : _object(object) {}

void RemoveCommand::execute() {
    _scene_manager->remove_object(*_object);
}
