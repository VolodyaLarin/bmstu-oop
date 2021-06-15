//
// Created by volodya on 01.06.2021.
//

#include "transformation.h"
#include "matrix_utils.h"
#include "coord/coord_solution.h"
#include <cmath>

std::shared_ptr<ICoord> Transformation::transform(const std::shared_ptr<ICoord> &coord) const {
    auto res = MatrixUtils::create_matrix<double>(1, DIMENSION + 1);

    auto vector = MatrixUtils::create_matrix<double>(1, DIMENSION + 1);

    vector[0][0] = coord->get_x();
    vector[0][1] = coord->get_y();
    vector[0][2] = coord->get_z();
    vector[0][3] = 1;

    MatrixUtils::multiply(vector, _data,  res);

    auto creator = CoordSolution().get_creator();
    return creator->create(
            res[0][0] / res[0][3],
            res[0][1] / res[0][3],
            res[0][2] / res[0][3]
            );
}

Transformation Transformation::join(const Transformation &transformation) const {
    auto new_data = MatrixUtils::create_matrix<double>(DIMENSION + 1, DIMENSION + 1);

    MatrixUtils::multiply(_data, transformation._data, new_data);

    Transformation tr;
    tr.set_data(new_data);

    return tr;
}

Transformation::Transformation() {
    for (int i = 0; i < DIMENSION + 1; ++i) {
        _data[i][i] = 1;
    }
}


RotateTransformation::RotateTransformation(const std::shared_ptr<ICoord> &rotation) {
    double x = rotation->get_x();
    double y = rotation->get_y();
    double z = rotation->get_z();

    set_data<std::initializer_list<std::initializer_list<double>>>(
        {
            {cos(y) * cos(z), cos(y) * sin(z), sin(y), 0},
            {- sin(x) * sin(y) * cos(z) - cos(x) * sin(z), -sin(x) * sin(y) * sin(z) + cos(x) * cos(z), sin(x) * cos(y), 0},
            {sin(x) * sin(z) - cos(x) * sin(y) * cos(z), -sin(x) * cos(z) - sin(y) * sin(z) * cos(x), cos(x) * cos(y), 0},
            {0, 0, 0, 1}
        }
    );
}

TranslateTransformation::TranslateTransformation(const std::shared_ptr<ICoord> &translate) {
    double x = translate->get_x();
    double y = translate->get_y();
    double z = translate->get_z();

    set_data<std::initializer_list<std::initializer_list<double>>>({
                     {1, 0, 0, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0},
                     {x, y, z, 1}
             });
}

ScaleTransformation::ScaleTransformation(const std::shared_ptr<ICoord> &scale) {
    double x = scale->get_x();
    double y = scale->get_y();
    double z = scale->get_z();

    set_data<std::initializer_list<std::initializer_list<double>>>({
                     {x, 0, 0, 0},
                     {0, y, 0, 0},
                     {0, 0, z, 0},
                     {0, 0, 0, 1}
             });
}

PerspectiveTransformation::PerspectiveTransformation(double k) {
    set_data<std::initializer_list<std::initializer_list<double>>>({
           {1, 0, 0, 0},
           {0, 1, 0, 0},
           {0, 0, 1, k},
           {0, 0, 0, 1}
   });
}
