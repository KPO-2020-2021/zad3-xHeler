#include "Rectangle.h"

Rectangle::Rectangle(){
    points[0] = Vector();
    points[1] = Vector();
    points[2] = Vector();
    points[3] = Vector();
}

Rectangle::Rectangle(Vector &v1, Vector &v2, Vector &v3, Vector &v4) {
    Rectangle();
    points[0] = v1;
    points[1] = v2;
    points[2] = v3;
    points[3] = v4;
}


bool operator==(Rectangle Rect1, Rectangle Rect2){
    return Rect1.points[0] == Rect2.points[0] &&
       Rect1.points[1] == Rect2.points[1] &&
       Rect1.points[2] == Rect2.points[2] &&
       Rect1.points[3] == Rect2.points[3];
}

void Rectangle::translationByVector(Vector &Vec){
    this->points[0] = Vec + (this->points[0]);
    this->points[1] = Vec + (this->points[1]);
    this->points[2] = Vec + (this->points[2]);
    this->points[3] = Vec + (this->points[3]);
}

void Rectangle::rotationUsingDegrees(double degree){
    Matrix rotation = Matrix(degree);
    this->points[0] = rotation * (this->points[0]);
    this->points[1] = rotation * (this->points[1]);
    this->points[2] = rotation * (this->points[2]);
    this->points[3] = rotation * (this->points[3]);
}

const Vector &Rectangle::operator[](int index) const {
    switch (index) {
        case 0:
            return this->points[0];
        case 1:
            return this->points[1];;
        case 2:
            return this->points[2];
        case 3:
            return this->points[3];
        default:
            throw std::invalid_argument("");
    }
}

Vector &Rectangle::operator[](int index) {
    switch (index) {
        case 0:
            return this->points[0];
        case 1:
            return this->points[1];;
        case 2:
            return this->points[2];
        case 3:
            return this->points[3];
        default:
            throw std::invalid_argument("");
    }
}

std::ostream &operator<<(std::ostream &ost, Rectangle &Rect) {
    Vector V1 = Rect.points[0];
    Vector V2 = Rect.points[1];
    Vector V3 = Rect.points[2];
    Vector V4 = Rect.points[3];
    ost << V1 << V2 << V3 << V4;
    return ost;
}

auto Rectangle::getCordinates() -> std::tuple<std::vector<double>, std::vector<double>> {
    std::vector<double> x, y;

    for (int i = 0; i < 4; i++) {
        x.push_back(points[i][0]); y.push_back(points[i][1]);
    }
    x.push_back(points[0][0]); y.push_back(points[0][1]);

    return {x, y};
}


