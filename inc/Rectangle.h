#ifndef ROTATIONS2D_RECTANGLE_H
#define ROTATIONS2D_RECTANGLE_H
#include <iostream>
#include <utility>
#include "Matrix.h"
#include "Vector.h"
#include <vector>
#include <tuple>

const int NUMBER_OF_POINTS = 4;

class Rectangle {
private:
    Vector points[NUMBER_OF_POINTS];
public:
    Rectangle();
    Rectangle(Vector &v1, Vector &v2, Vector &v3, Vector &v4);
    friend bool operator==(Rectangle Rect1, Rectangle Rect2);
    const Vector & operator[](int index) const;
    Vector & operator[](int index);
    void rotationUsingDegrees(double degree);
    void translationByVector(Vector &Vec);
    friend std::ostream & operator<<(std::ostream & ost, Rectangle &Rect);
    auto getCordinates() -> std::tuple<std::vector<double>, std::vector<double>>;
};

#endif //ROTATIONS2D_RECTANGLE_H
