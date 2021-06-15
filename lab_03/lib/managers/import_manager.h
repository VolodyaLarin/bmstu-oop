//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_IMPORT_MANAGER_H
#define LAB03_IMPORT_MANAGER_H


#include "i_manager.h"
#include "../objects/model.h"
#include "../import/i_importer.h"

class ImportManager: public IManager{
private:
    std::shared_ptr<IImporter> _importer;
public:
    std::shared_ptr<Model> import(std::istream& stream);

    [[nodiscard]] const std::shared_ptr<IImporter> &get_importer() const;

    void set_importer(const std::shared_ptr<IImporter> &importer);
};


#endif //LAB03_IMPORT_MANAGER_H
