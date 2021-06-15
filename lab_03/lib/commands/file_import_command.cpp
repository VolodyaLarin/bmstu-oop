//
// Created by volodya on 05.06.2021.
//

#include "file_import_command.h"


FileImportCommand::FileImportCommand(const std::string& filename): _command(_stream) {
    _stream.open(filename, std::ios_base::in);
}

void FileImportCommand::execute() {
    _command.execute();
}

FileImportCommand::~FileImportCommand() {
    _stream.close();
}
