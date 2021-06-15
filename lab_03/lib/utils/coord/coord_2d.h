//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_COORD_2_D_H
#define LAB03_COORD_2_D_H


#include "i_coord_2d.h"

class Coord2d: public ICoord2d{
private:
    double _x = 0;
    double _y = 0;
public:
    Coord2d() = default;
    Coord2d(double x, double y);

    [[nodiscard]] double get_x() const override;

    void set_x(double x) override;

    [[nodiscard]] double get_y() const override;

    void set_y(double y) override;
};


#endif //LAB03_COORD_2_D_H
