//
// Created by eyeboy on 2018/7/1.
//

#include "gtest/gtest.h"
#include "valid_parentheses.hpp"

using namespace valid_parentheses;

TEST(valid_parentheses, solution) {
    EXPECT_TRUE(solution("()"));
    EXPECT_TRUE(solution("()[]{}"));
    EXPECT_FALSE(solution("(]"));
    EXPECT_FALSE(solution("([)]"));
    EXPECT_TRUE(solution("{()}"));
}