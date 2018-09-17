//
// Created by eyeboy on 2018/9/17.
//
#include "gtest/gtest.h"
#include "climbing_stairs.hpp"

using namespace climbing_stairs;

TEST(climbing_stairs, solution) {
    EXPECT_EQ(solution_2(2), 2);
    EXPECT_EQ(solution_2(3), 3);
}