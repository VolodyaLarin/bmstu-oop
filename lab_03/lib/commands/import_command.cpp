//
// Created by volodya on 05.06.2021.
//

#include "import_command.h"
#include "../managers/creators/import_manager_creator.h"

ImportCommand::ImportCommand(std::istream &stream) : _stream(stream) {
    _import_manager = ImportManagerCreator().create();
}

void ImportCommand::execute() {
    auto model = _import_manager->import(_stream);

    ObjectPtr object = model;

    _scene_manager->add_object(object);
}
