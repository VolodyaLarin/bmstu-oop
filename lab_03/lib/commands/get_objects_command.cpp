//
// Created by volodya on 05.06.2021.
//

#include "get_objects_command.h"

void GetObjectsCommand::execute() {
    begin = _scene_manager->get_scene().begin();
    end = _scene_manager->get_scene().end();
}

GetObjectsCommand::GetObjectsCommand(Array<ObjectPtr>::iterator &begin,
                                     Array<ObjectPtr>::iterator &anEnd) : begin(begin),
                                                                                               end(anEnd) {}
