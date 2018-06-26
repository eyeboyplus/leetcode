//
// Created by eyeboy on 2018/6/26.
//

#include "gtest/gtest.h"
#include "integer_to_roman.hpp"

TEST(integer_to_roman, solution_1) {
    EXPECT_EQ(solution_1(3), "III");
    EXPECT_EQ(solution_1(4), "IV");
    EXPECT_EQ(solution_1(9), "IX");
    EXPECT_EQ(solution_1(58), "LVIII");
    EXPECT_EQ(solution_1(1994), "MCMXCIV");
    EXPECT_EQ(solution_1(10), "X");
}