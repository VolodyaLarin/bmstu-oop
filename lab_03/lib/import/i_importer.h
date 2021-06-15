//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_I_IMPORTER_H
#define LAB03_I_IMPORTER_H

#include "../objects/model.h"

class IImporter {
public:
    virtual std::shared_ptr<Model> import(std::istream &istream) = 0;
};


#endif //LAB03_I_IMPORTER_H
