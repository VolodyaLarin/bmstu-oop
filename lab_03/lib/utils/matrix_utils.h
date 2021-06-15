//
// Created by volodya on 02.06.2021.
//

#include "../array.h"

#ifndef LAB03_MATRIX_UTILS_H
#define LAB03_MATRIX_UTILS_H

template<class T>
using Matrix = Array<Array<T>>;

class MatrixUtils {
public:
    template<class T>
    static Matrix<T> create_matrix(int i, int j);

    template<class T>
    static void multiply(const T& a, const T& b, T& res);
};

template<class T>
void MatrixUtils::multiply(const T& a, const T& b, T& res) {
    int rows = a.size();
    int cols = b.size();
    int K = b[0].size();

    if (res.size() != rows || res[0].size() != cols)
        throw;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < cols; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

template<class T>
Array<Array<T>> MatrixUtils::create_matrix(int rows, int cols) {
    Array<Array<T>> _data;
    _data.resize(rows);
    for (int i =0; i < rows; ++i) {
        _data[i].resize(cols);
        for (int j = 0; j < cols; ++j) {
            _data[i][j] = 0;
        }
    }
    return _data;
}


#endif //LAB03_MATRIX_UTILS_H
