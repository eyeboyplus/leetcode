//
// Created by eyeboy on 2018/9/15.
//
#include "gtest/gtest.h"
#include "sqrt_x.hpp"

using namespace sqrt_x;

TEST(sqrt_x, solution) {
    EXPECT_EQ(solution(4), 2);
    EXPECT_EQ(solution(8), 2);
    EXPECT_EQ(solution(1), 1);
    EXPECT_EQ(solution(9), 3);
}