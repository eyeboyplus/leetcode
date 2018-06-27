//
// Created by eyeboy on 2018/6/27.
//
#include <gtest/gtest.h>

#include "wildcard_matching.hpp"

using namespace wildcard_matching;

TEST(wildcard_matching, solution_1) {
    EXPECT_FALSE(solution_1("aa", "a"));
    EXPECT_TRUE(solution_1("aa", "*"));
    EXPECT_FALSE(solution_1("cb", "?"));
    EXPECT_TRUE(solution_1("adceb", "a*b"));
    EXPECT_FALSE(solution_1("acdcb", "a*c?b"));
    EXPECT_FALSE(solution_1("mississippi", "m??*ss*?i*pi"));
    EXPECT_TRUE(solution_1("ho", "ho**"));
}