//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_MY_FORMAT_IMPORTER_H
#define LAB03_MY_FORMAT_IMPORTER_H


#include "i_importer.h"
#include "../objects/model.h"

class MyFormatImporter: public IImporter{
public:
    std::shared_ptr<Model> import(std::istream &istream) override;

private:
    Array<std::pair<size_t, size_t>> _import_edges(std::istream &istream) const;
    Array<std::shared_ptr<ICoord>> _import_points(std::istream &istream) const;
};


#endif //LAB03_MY_FORMAT_IMPORTER_H
