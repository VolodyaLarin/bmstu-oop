//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_POINT_H
#define LAB03_POINT_H


#include "../../utils/coord/i_coord.h"

class Point {
private:
    std::shared_ptr<ICoord> _coord;
public:
    [[nodiscard]] const std::shared_ptr<ICoord> &get_coord() const;

    void set_coord(const std::shared_ptr<ICoord> &coord);
};


#endif //LAB03_POINT_H
