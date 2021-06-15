//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_I_COORD_2D_H
#define LAB_03_QT_I_COORD_2D_H


class ICoord2d {
public:
    [[nodiscard]] virtual double get_x() const = 0;

    virtual void set_x(double x) = 0;

    [[nodiscard]] virtual double get_y() const = 0;

    virtual void set_y(double y) = 0;

    virtual ~ICoord2d() = default;

};


#endif //LAB_03_QT_I_COORD_2D_H
