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

//Normalnums
TEST(Normalnums, num1) {
    qvadr(1, -5, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(4, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(Normalnums, num2) {
    qvadr(-4, 5, -1, &x1, &x2, &flag);
    ASSERT_EQ(1, x2);
    ASSERT_FLOAT_EQ(0.25, x1);
    ASSERT_EQ(0, flag);
}

TEST(Normalnums, num3) {
    qvadr(1, 2, 1, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-1, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

TEST(Normalnums, num4) {
    qvadr(1, -6, 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

TEST(Zerokoef, num1) {
    qvadr(0, 2, 2, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(x1, x2);
    ASSERT_FLOAT_EQ(x1, -1);
    ASSERT_EQ(flag, 0);
}

TEST(Zerokoef, num2) {
    qvadr(0, 0, 2, &x1, &x2, &flag);
    ASSERT_EQ(flag, 1);
}

#endif // QVADR_H
