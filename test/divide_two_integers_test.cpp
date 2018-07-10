//
// Created by eyeboy on 2018/7/7.
//

#include "gtest/gtest.h"
#include "divide_two_integers.hpp"

using namespace divide_two_integers;

TEST(divide_two_integers, solution_1) {
    EXPECT_EQ(solution_1(10, 3), 3);
    EXPECT_EQ(solution_1(7, -3), -2);
    EXPECT_EQ(solution_1(-2147483648, 1), -2147483648);
}