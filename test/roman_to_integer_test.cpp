//
// Created by eyeboy on 2018/6/27.
//

#include "gtest/gtest.h"
#include "roman_to_integer.hpp"

using namespace roman_to_integer;

TEST(ROMAN_TO_INTEGER, solution) {
    EXPECT_EQ(romanToInt("III"), 3);
    EXPECT_EQ(romanToInt("IV"), 4);
    EXPECT_EQ(romanToInt("IX"), 9);
    EXPECT_EQ(romanToInt("LVIII"), 58);
    EXPECT_EQ(romanToInt("MCMXCIV"), 1994);
}