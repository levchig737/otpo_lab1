#ifndef QVADR_H
#define QVADR_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "myfunc.h"
}

float x1, x2;
int flag;

//WholeRoots
TEST(WholeRoots, num1) {
    qvadr(1, -5, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(4, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(WholeRoots, num2) {
    qvadr(-1, 9, -8, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1, x1);
    ASSERT_FLOAT_EQ(8, x2);
    ASSERT_EQ(0, flag);
}

//FractionalRoots
TEST(FraclionalRoots, num1) {
    qvadr(2, -9, 7, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(3.5, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(FraclionalRoots, num2) {
    qvadr(5, -11, 3, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1.881025, x1);
    ASSERT_FLOAT_EQ(0.318975, x2);
    ASSERT_EQ(0, flag);
}

TEST(FraclionalRoots, num3) {
    qvadr(-7, 13, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.32702827, x1);
    ASSERT_FLOAT_EQ(2.18417113, x2);
    ASSERT_EQ(0, flag);
}

//ZeroDiscriminant

TEST(ZeroDiscriminant, num1) {
    qvadr(1, 2, 1, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-1, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

TEST(ZeroDiscriminant, num2) {
    qvadr(2, -6, 4.5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1.5, x1);
    ASSERT_FLOAT_EQ(1.5, x2);
    ASSERT_EQ(0, flag);
}

//NoRoots
TEST(NoRoots, num1) {
    qvadr(1, -6, 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

TEST(NoRoots, num2) {
    qvadr(-7, 13, -15, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

TEST(NoRoots, num3) {
    qvadr(1, 0, 3, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

#endif // QVADR_H
