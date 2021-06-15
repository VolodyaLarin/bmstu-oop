//
// Created by volodya on 05.06.2021.
//

#ifndef LAB_03_QT_FILE_IMPORT_COMMAND_H
#define LAB_03_QT_FILE_IMPORT_COMMAND_H


#include <fstream>
#include "i_command.h"
#include "import_command.h"

class FileImportCommand: public ICommand {
private:
    std::fstream _stream;
    ImportCommand _command;
public:
    FileImportCommand(const std::string& filename);

    void execute() override;

    ~FileImportCommand();
};


#endif //LAB_03_QT_FILE_IMPORT_COMMAND_H
