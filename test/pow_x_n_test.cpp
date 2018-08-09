//
// Created by eyeboy on 2018/8/9.
//
#include "gtest/gtest.h"
#include "pow_x_n.hpp"

using namespace pow_x_n;

TEST(pow_x_n, solution) {
    EXPECT_EQ(solution(2.0, 10), 1024.0);
    EXPECT_EQ(solution(2.1, 3), 9.261);
    EXPECT_EQ(solution(2.0, -2), 0.25);
    EXPECT_EQ(solution(1.0, -2147483648), 1.0);
}