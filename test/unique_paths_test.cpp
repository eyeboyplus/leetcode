//
// Created by eyeboy on 2018/9/6.
//
#include "gtest/gtest.h"
#include "unique_paths.hpp"

using namespace unique_paths;

TEST(unique_paths, solution) {
    EXPECT_EQ(solution_2(3, 2), 3);
    EXPECT_EQ(solution_2(7, 3), 28);
}
