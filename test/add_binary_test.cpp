//
// Created by eyeboy on 2018/9/12.
//
#include "gtest/gtest.h"
#include "add_binary.hpp"

using namespace add_binary;

TEST(add_binary, solution) {
    EXPECT_EQ(solution("11", "1"), "100");
    EXPECT_EQ(solution("1010", "1011"), "10101");
}