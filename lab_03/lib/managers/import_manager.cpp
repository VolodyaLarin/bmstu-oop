//
// Created by volodya on 05.06.2021.
//

#include "import_manager.h"

std::shared_ptr<Model> ImportManager::import(std::istream &stream) {
    return _importer->import(stream);
}

const std::shared_ptr<IImporter> &ImportManager::get_importer() const {
    return _importer;
}

void ImportManager::set_importer(const std::shared_ptr<IImporter> &importer) {
    _importer = importer;
}
