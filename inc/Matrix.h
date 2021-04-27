#include <cmath>
#include "Vector.h"

#ifndef ROTATIONS2D_MATRIX_H
#define ROTATIONS2D_MATRIX_H

constexpr int SIZE = 4;

class Matrix {
private:
    double matrix[SIZE];

public:
    Matrix();
    Matrix(double angle);


    bool operator==(const Matrix & matrix2D);
    double & operator[](int index);
    const double & operator[](int index) const;
    Vector operator*(const Vector & vector);
};

#endif //ROTATIONS2D_MATRIX_H
