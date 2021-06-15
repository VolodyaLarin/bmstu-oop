//
// Created by volodya on 10.06.2021.
//

#ifndef LAB_03_QT_I_COORD_H
#define LAB_03_QT_I_COORD_H

#include <memory>

class ICoord {
public:
    [[nodiscard]] virtual double get_x() const = 0;

    virtual void set_x(double x) = 0;

    [[nodiscard]] virtual double get_y() const = 0;

    virtual void set_y(double y) = 0;

    [[nodiscard]] virtual double get_z() const = 0;

    virtual void set_z(double z) = 0;

    virtual std::shared_ptr<ICoord> inverse() const = 0;

    virtual ~ICoord() = default;
};


#endif //LAB_03_QT_I_COORD_H
