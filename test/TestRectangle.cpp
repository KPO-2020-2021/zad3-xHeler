#include "gtest/gtest.h"
#include "Rectangle.h"

TEST (Rectangle, emptyConstructorRectangle) {
    Vector v1, v2, v3, v4;
    Rectangle rect();
    Rectangle tmp(v1, v2, v3, v4);
    EXPECT_EQ(tmp, rect);
}

TEST (Rectangle, constructorRectangle) {
    Vector v1(0, 0);
    Vector v2(1, 0);
    Vector v3(0, 1);
    Vector v4(1, 1);
    Rectangle rect(v1, v2, v3, v4);
    EXPECT_EQ(rect[0],  Vector(0, 0));
    EXPECT_EQ(rect[1],  Vector(1, 0));
    EXPECT_EQ(rect[2],  Vector(0, 1));
    EXPECT_EQ(rect[3],  Vector(1, 1));
}

TEST (Rectangle, rotationRectangle) {
    Vector v1(0, 0);
    Vector v2(1, 0);
    Vector v3(0, 1);
    Vector v4(1, 1);
    Rectangle rect(v1, v2, v3, v4);
    rect.rotationUsingDegrees(360);

    EXPECT_EQ(rect[0],  Vector(0, 0));
    EXPECT_EQ(rect[1],  Vector(1, 0));
    EXPECT_EQ(rect[2],  Vector(0, 1));
    EXPECT_EQ(rect[3],  Vector(1, 1));
}
