//
// Created by volodya on 10.06.2021.
//

#include "coord_solution.h"
#include "coord_creator.h"

std::shared_ptr<ICoordCreator> CoordSolution::get_creator() const {
    return std::make_shared<CoordCreator>();
}

