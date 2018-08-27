//
// Created by eyeboy on 2018/7/27.
//
#include "gtest/gtest.h"
#include "multiply_strings.hpp"

#include <iostream>

using namespace multiply_strings;

TEST(multiply_strings, solution) {
    EXPECT_EQ(solution("2", "3"), "6");
    EXPECT_EQ(solution("123", "456"), "56088");
    EXPECT_EQ(solution("9133", "0"), "0");
    std::cout << "";
}

