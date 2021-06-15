//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_VECTOR_H
#define LAB03_VECTOR_H


#include "coord/coord.h"

class Vector {
private:
    std::shared_ptr<ICoord> _begin = {};
    std::shared_ptr<ICoord> _end = {};
public:
    Vector() = default;

    Vector(const std::shared_ptr<ICoord> &begin, const std::shared_ptr<ICoord> &end);

    [[nodiscard]] const std::shared_ptr<ICoord> &get_begin() const;

    void set_begin(const std::shared_ptr<ICoord> &begin);

    [[nodiscard]] const std::shared_ptr<ICoord> &get_end() const;

    void set_end(const std::shared_ptr<ICoord> &end);

    [[nodiscard]] std::shared_ptr<ICoord> get_rotation() const;

    [[nodiscard]] double get_dx() const;
    [[nodiscard]] double get_dy() const;
    [[nodiscard]] double get_dz() const;
    [[nodiscard]] std::shared_ptr<ICoord> get_d() const;
    [[nodiscard]] double get_size() const;



};


#endif //LAB03_VECTOR_H
