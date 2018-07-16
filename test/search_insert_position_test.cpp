//
// Created by eyeboy on 2018/7/16.
//
#include "gtest/gtest.h"
#include "search_insert_position.hpp"

using namespace search_insert_position;

TEST(search_insert_position, solution) {
    vector<int> vec = {1, 3, 5, 6};
    vector<int> vec1 = {1};
    vector<int> vec2 = {};
    EXPECT_EQ(solution_1(vec, 5), 2);
    EXPECT_EQ(solution_1(vec, 2), 1);
    EXPECT_EQ(solution_1(vec, 7), 4);
    EXPECT_EQ(solution_1(vec, 0), 0);
    EXPECT_EQ(solution_1(vec1, 1), 0);
    EXPECT_EQ(solution_1(vec2, 0), 0);
}