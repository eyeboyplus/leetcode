//
// Created by eyeboy on 2018/7/13.
//

#include "gtest/gtest.h"
#include "longest_valid_parentheses.hpp"

using namespace longest_valid_parentheses;

TEST(longest_valid_parentheses, solution) {
    EXPECT_EQ(solution_2("(()"), 2);
    EXPECT_EQ(solution_2(")()())"), 4);
    EXPECT_EQ(solution_2("()(()"), 2);
    EXPECT_EQ(solution_2("()(())"), 6);
}