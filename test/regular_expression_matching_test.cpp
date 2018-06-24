//
// Created by eyeboy on 2018/6/24.
//
#include <gtest/gtest.h>

#include "regular_expression_matching.hpp"

TEST(regular_expression_matching_test, solution_1) {
    EXPECT_FALSE(solution_1("aa", "a"));
    EXPECT_TRUE(solution_1("aa", "a*"));
    EXPECT_TRUE(solution_1("ab", ".*"));
    EXPECT_TRUE(solution_1("aab", "c*a*b"));
    EXPECT_FALSE(solution_1("mississippi", "mis*is*p*"));
    EXPECT_TRUE(false);
}
