//
// Created by eyeboy on 2018/8/1.
//
#include "gtest/gtest.h"
#include "jump_game_ii.hpp"

using namespace jump_game_ii;

TEST(jump_game_ii, solution) {
    vector<int> vec1 = {2,3,1,1,4};
    vector<int> vec2 = {1,1,1,1,1};
    EXPECT_EQ(solution_1(vec1), 2);
    EXPECT_EQ(solution_1(vec2), 4);
}