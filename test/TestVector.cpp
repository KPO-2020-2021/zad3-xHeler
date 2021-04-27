#include "gtest/gtest.h"
#include "Vector.h"

TEST (Vector, emptyConstructor) {
    Vector v;
    EXPECT_TRUE(v == Vector(0, 0, 0));
}

TEST (Vector, constructor2D) {
    Vector v(2, 3);
    EXPECT_TRUE(v[0] == 2);
    EXPECT_TRUE(v[1] == 3);
    EXPECT_TRUE(v[2] == 0);
}

TEST (Vector, constructor3D) {
    Vector v(1.95, -99.52, 0.22);
    EXPECT_TRUE(v[0] == 1.95);
    EXPECT_TRUE(v[1] == -99.52);
    EXPECT_TRUE(v[2] == 0.22);
}

TEST (Vector, calculateModulo) {
    Vector v(4,3);
    EXPECT_TRUE(v.modulo() == 5);
}

TEST (Vector, addTwoVectors) {
    Vector v(2, 3, 5);
    Vector w(-1, 5, 11);
    EXPECT_TRUE(v + w == Vector(1, 8, 16));
}

TEST (Vector, substractTwoVectors) {
    Vector v(5, 2.5, 10);
    Vector w(5, 5, 10);
    EXPECT_TRUE(v - w == Vector(0, -2.5, 0));
}

TEST (Vector, multipleByConstans) {
    Vector v(5, 1, 2.5);
    int constans = 5;
    EXPECT_TRUE(v * constans == Vector(25, 5, 12.5));
    EXPECT_TRUE( -1 * v == Vector(-5, -1, -2.5));
}

TEST (Vector, multipleTwoVectors) {
    Vector v(1, 2, 3);
    Vector w(0, 1, 2);
    EXPECT_TRUE(v * w == Vector(1, -2, 1));
}

TEST (Vector, calculateScalar) {
    Vector v(1, 2, 3);
    Vector w(0, 1, 2);
    EXPECT_TRUE(v % w == 8);
}

TEST (Vector, useIndex) {
    Vector v(1, 2, 3);
    EXPECT_TRUE(v[2] == 3);
}
