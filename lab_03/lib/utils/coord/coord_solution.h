//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_COORD_SOLUTION_H
#define LAB_03_QT_COORD_SOLUTION_H


#include <memory>
#include "i_coord_creator.h"

class CoordSolution {
public:
    [[nodiscard]] std::shared_ptr<ICoordCreator> get_creator() const;
};


#endif //LAB_03_QT_COORD_SOLUTION_H
