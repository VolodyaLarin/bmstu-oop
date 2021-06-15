//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_COORD_H
#define LAB03_COORD_H


#include "coord_2d.h"
#include "i_coord.h"

class Coord: public ICoord {
private:
    double _x = 0;
    double _y = 0;
    double _z = 0;
public:
    Coord() = default;
    Coord(double x, double y, double z);

    [[nodiscard]] double get_x() const override;

    void set_x(double x) override;

    [[nodiscard]] double get_y() const override;

    void set_y(double y) override;

    [[nodiscard]] double get_z() const override;

    void set_z(double z) override;

    [[nodiscard]] std::shared_ptr<ICoord> inverse() const override;

};

typedef Coord Rotation, Scale;

#endif //LAB03_COORD_H
