//
// Created by eyeboy on 2018/7/19.
//

#include "gtest/gtest.h"
#include "count_and_say.hpp"


using namespace count_and_say;

TEST(count_and_say, solution) {
    EXPECT_EQ(solution(4), "1211");
    EXPECT_EQ(solution(5), "111221");
}