//
// Created by volodya on 05.06.2021.
//

#include "import_manager_creator.h"
#include "../import_manager.h"

std::shared_ptr <ImportManager> ImportManagerCreator::create() {
    static auto _manager = std::make_shared<ImportManager>();

    return _manager;
}
