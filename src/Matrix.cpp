#include <stdexcept>
#include <cmath>
#include "Matrix.h"

Matrix::Matrix() {
    *this = Matrix(0);
}

Matrix::Matrix(double angle) {
    angle = (M_PI / 180) * angle;
    matrix[0] = cos(angle);
    matrix[1] = -sin(angle);
    matrix[2] = sin(angle);
    matrix[3] = cos(angle);
}

bool Matrix::operator==(const Matrix & matrix2D) {
    return matrix[0] == matrix2D.matrix[0] && matrix[1] == matrix2D.matrix[1] &&
           matrix[2] == matrix2D.matrix[2] && matrix[3] == matrix2D.matrix[3];
}

double & Matrix::operator[](int index) {
    switch (index) {
        case 0:
            return matrix[0];
        case 1:
            return matrix[1];
        case 2:
            return matrix[2];
        case 3:
            return matrix[3];
        default:
            throw std::out_of_range("Index out of range!");
    }
}

const double & Matrix::operator[](const int index) const {
    switch (index) {
        case 0:
            return matrix[0];
        case 1:
            return matrix[1];
        case 2:
            return matrix[2];
        case 3:
            return matrix[3];
        default:
            throw std::out_of_range("Index out of range!");
    }
}

Vector Matrix::operator*(const Vector &vector) {
    Vector tmp;
    tmp[0] = vector[0] * matrix[0] + vector[1] * matrix[1];
    tmp[1] = vector[0] * matrix[2] + vector[1] * matrix[3];
    return tmp;
}





