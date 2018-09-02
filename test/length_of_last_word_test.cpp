//
// Created by eyeboy on 2018/9/2.
//

#include "gtest/gtest.h"
#include "length_of_last_word.hpp"

using namespace length_of_last_word;

TEST(length_of_last_word, solution) {
    EXPECT_EQ(solution("Hello World"), 5);
    EXPECT_EQ(solution("World"), 5);
    EXPECT_EQ(solution("HelloWorld"), 10);
    EXPECT_EQ(solution("a "), 1);
    EXPECT_EQ(solution("b  a  "), 1);
}