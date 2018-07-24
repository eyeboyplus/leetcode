//
// Created by eyeboy on 2018/7/24.
//
#include "gtest/gtest.h"
#include "first_missing_positive.hpp"

using namespace first_missing_positive;

TEST(first_missing_positive, solution) {

    vector<int> vec1 = {1, 2, 0};
    vector<int> vec2 = {3, 4, -1, 1};
    vector<int> vec3 = {7, 8, 9};
    vector<int> vec4 = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution(vec1), 3);
    EXPECT_EQ(solution(vec2), 2);
    EXPECT_EQ(solution(vec3), 1);
    EXPECT_EQ(solution(vec4), 6);
    EXPECT_EQ(solution_1(vec1), 3);
    EXPECT_EQ(solution_1(vec2), 2);
    EXPECT_EQ(solution_1(vec3), 1);
    EXPECT_EQ(solution_1(vec4), 6);
}