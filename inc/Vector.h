#include <cmath>

#ifndef ROTATIONS2D_VECTOR_H
#define ROTATIONS2D_VECTOR_H

const int PRECISION = 10;

class Vector {
private:
    double x;
    double y;
    double z;
public:
    Vector();
    Vector(double x, double y, double z = 0);

    friend bool operator==(const Vector & v, const Vector & w);
    Vector operator+(const Vector & v);
    Vector operator-(const Vector & v);
    friend Vector operator*(const Vector & v, const int & w);
    friend Vector operator*(const int & w, const Vector & v);
    Vector operator*(const Vector & v);
    friend double operator%(const Vector & v, const Vector & w);
    const double & operator[](int index) const;
    double & operator[](int index);
    friend std::ostream & operator<<(std::ostream & ost, const Vector &Vec);
    friend std::istream & operator>>(std::istream & ist, Vector &Vec);

    double modulo();
};

#endif //ROTATIONS2D_VECTOR_H
