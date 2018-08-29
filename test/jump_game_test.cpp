//
// Created by eyeboy on 2018/8/29.
//

#include "gtest/gtest.h"
#include "jump_game.hpp"

using namespace jump_game;

TEST(jump_game, solution) {
    vector<int> vec1 {2,3,1,1,4};
    EXPECT_TRUE(solution_2(vec1));

    vector<int>vec2 {3,2,1,0,4};
    EXPECT_FALSE(solution_2(vec2));

    vector<int>vec3 {2, 5, 0, 0};
    EXPECT_TRUE(solution_2(vec3));
}