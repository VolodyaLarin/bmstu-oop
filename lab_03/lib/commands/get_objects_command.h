//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_GET_OBJECTS_COMMAND_H
#define LAB_03_QT_GET_OBJECTS_COMMAND_H


#include "a_scene_command.h"

class GetObjectsCommand: public ASceneCommand {
private:
    Array<ObjectPtr>::iterator &begin;
    Array<ObjectPtr>::iterator &end;
public:
    GetObjectsCommand(Array<ObjectPtr>::iterator &begin,
                      Array<ObjectPtr>::iterator &anEnd);

    void execute() override;
};


#endif //LAB_03_QT_GET_OBJECTS_COMMAND_H
