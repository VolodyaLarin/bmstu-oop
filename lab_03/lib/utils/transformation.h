//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_TRANSFORMATION_H
#define LAB03_TRANSFORMATION_H

#include <initializer_list>
#include "coord/coord.h"
#include "../array.h"
#include "matrix_utils.h"

#define DIMENSION 3

class Transformation {
protected:
    Matrix<double> _data = MatrixUtils::create_matrix<double>(DIMENSION + 1, DIMENSION + 1);

    template<class T>
    void set_data(const T &list);
public:
    Transformation();

    [[nodiscard]] std::shared_ptr<ICoord> transform(const std::shared_ptr<ICoord>& coord) const;

    [[nodiscard]] Transformation join(const Transformation& transformation) const;
};


template<class T>
void Transformation::set_data(const T &list) {
    if (list.size() != DIMENSION + 1)
        throw;
    int i = 0;
    for (const auto &row: list) {

        if (row.size() != DIMENSION + 1)
            throw;
        int j = 0;
        for (const auto &item: row) {
            _data[i][j] = item;
            ++j;
        }
        ++i;
    }
}

class RotateTransformation: public Transformation {
public:
    explicit RotateTransformation(const std::shared_ptr<ICoord>& rotation);
};

class PerspectiveTransformation: public Transformation {
public:
    explicit PerspectiveTransformation(double k = -0.1);
};


class TranslateTransformation: public Transformation {
public:
    explicit TranslateTransformation(const std::shared_ptr<ICoord>& translate);
};

class ScaleTransformation: public Transformation {
public:
    explicit ScaleTransformation(const std::shared_ptr<ICoord>& scale);
};

#endif //LAB03_TRANSFORMATION_H
