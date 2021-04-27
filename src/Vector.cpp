#include <stdexcept>
#include <iostream>
#include <ios>
#include <iomanip>
#include "Vector.h"

const double PRECISION_RIFFLE = 0.001;

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

//! OPERATORS

bool operator==(const Vector &v, const Vector &w) {
    return std::abs(v.x - w.x) < PRECISION_RIFFLE &&
           std::abs(v.y - w.y) < PRECISION_RIFFLE &&
           std::abs(v.z - w.z) < PRECISION_RIFFLE;
}

Vector Vector::operator+(const Vector & v) {
    return Vector(v.x + x, v.y + y , v.z + z);
}

Vector Vector::operator-(const Vector & v) {
    return Vector(x - v.x, y - v.x , z - v.z);
}

Vector operator*(const Vector &v, const int &w) {
    return Vector(v.x * w, v.y * w, v.z * w);
}

Vector operator*(const int &w, const Vector &v) {
    return v * w;
}

Vector Vector::operator*(const Vector &v) {
    return Vector(y * v.z - v.y * z, -(x * v.z - v.x * z), x * v.y - v.x * y);
}

double operator%(const Vector &v, const Vector &w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

double & Vector::operator[](const int index) {
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::out_of_range("Index out of range!");
    }
}

const double &Vector::operator[](int index) const {
    switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::out_of_range("Index out of range!");
    }
}


//! METHODS

double Vector::modulo() {
    double result = sqrt(x * x + y * y + z * z);
    return result > 0 ? result : 0;
}

std::ostream &operator<<(std::ostream &ost, const Vector &Vec) {
    std::cout << std::fixed;
    std::cout << std::setprecision(PRECISION);
    ost << Vec.x << " ";
    ost << Vec.y << std::endl;
    return ost;
}

std::istream &operator>>(std::istream &ist, Vector &Vec) {
    double x,y;
    std::cout << "x:\n";
    ist >> x;
    Vec[0] = x;

    std::cout << "y\n";
    ist >> y;
    Vec[1] = y;

    return ist;
}


