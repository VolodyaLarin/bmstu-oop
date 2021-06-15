//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_IMPORT_MANAGER_CREATOR_H
#define LAB03_IMPORT_MANAGER_CREATOR_H


#include <memory>
#include "../import_manager.h"
#include "i_manager_creator.h"

class ImportManagerCreator: public IManagerCreator {
public:
    std::shared_ptr<ImportManager> create();
};


#endif //LAB03_IMPORT_MANAGER_CREATOR_H
