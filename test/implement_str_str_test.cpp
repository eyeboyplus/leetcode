//
// Created by eyeboy on 2018/7/6.
//

#include "gtest/gtest.h"
#include "implement_str_str.hpp"

using namespace implement_str_str;

TEST(implement_str_str, solution_1) {
    EXPECT_EQ(solution_1("hello", "ll"), 2);
    EXPECT_EQ(solution_1("aaaaa", "bba"), -1);
    EXPECT_EQ(solution_1("aaa", "aaaa"), -1);
}