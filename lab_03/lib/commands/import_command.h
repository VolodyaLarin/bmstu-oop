//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_IMPORT_COMMAND_H
#define LAB_03_QT_IMPORT_COMMAND_H


#include <memory>
#include "../managers/import_manager.h"
#include "a_scene_command.h"

class ImportCommand: public ASceneCommand{
protected:
    std::shared_ptr<ImportManager> _import_manager;
    std::istream &_stream;
public:
    ImportCommand(std::istream &stream);

    void execute() override;
};


#endif //LAB_03_QT_IMPORT_COMMAND_H
