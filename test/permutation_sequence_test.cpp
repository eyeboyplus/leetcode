//
// Created by eyeboy on 2018/9/4.
//
#include "gtest/gtest.h"
#include "permutation_sequence.hpp"

using namespace permutation_sequence;

TEST(permutation_sequence, solution) {
    EXPECT_EQ(solution_2(3, 3), "213");
    EXPECT_EQ(solution_2(4, 9), "2314");
}
