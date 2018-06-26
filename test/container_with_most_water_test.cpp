//
// Created by eyeboy on 2018/6/26.
//
#include "gtest/gtest.h"
#include "container_with_most_water.hpp"

using namespace container_with_most_water;

TEST(container_with_most_water, solution_1) {
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    EXPECT_EQ(solution_1(vec), 10);
}