#include "gtest/gtest.h"
#include "Matrix.h"

TEST (Matrix2D, emptyConstructorMatrix2D) {
    Matrix matrix;
    Matrix expected(0);
    EXPECT_NEAR(matrix[0],  expected[0], 0.0001);
    EXPECT_NEAR(matrix[1], expected[1] , 0.0001);
    EXPECT_NEAR(matrix[2], expected[2] , 0.0001);
    EXPECT_NEAR(matrix[3], expected[3] , 0.0001);
}

TEST (Matrix2D, defaultConstructor) {
    Matrix matrix(90);
    EXPECT_NEAR(matrix[0], 0 , 0.0001);
    EXPECT_NEAR(matrix[1], -1 , 0.0001);
    EXPECT_NEAR(matrix[2], 1 , 0.0001);
    EXPECT_NEAR(matrix[3], 0 , 0.0001);
}

TEST (Matrix2D, unusualConstructor) {
    Matrix matrix(45);
    EXPECT_NEAR(matrix[0], 0.70710678 , 0.0001);
    EXPECT_NEAR(matrix[1], -0.70710678 , 0.0001);
    EXPECT_NEAR(matrix[2], 0.70710678 , 0.0001);
    EXPECT_NEAR(matrix[3], 0.70710678 , 0.0001);
}

TEST (Matrix2D, unfriendlyAngelConstructor) {
    Matrix matrix(87);
    EXPECT_NEAR(matrix[0], 0.0523359 , 0.0001);
    EXPECT_NEAR(matrix[1], -0.99862953 , 0.0001);
    EXPECT_NEAR(matrix[2], 0.99862953 , 0.0001);
    EXPECT_NEAR(matrix[3], 0.0523359 , 0.0001);
}

TEST (Matrix2D, rotationByAngel) {
    Matrix matrix2D(90);
    Vector v(1, 1);
    v = matrix2D * v;
    EXPECT_NEAR(v[0], -1, 0.001);
    EXPECT_NEAR(v[1], 1, 0.001);
}