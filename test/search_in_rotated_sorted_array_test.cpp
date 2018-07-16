//
// Created by eyeboy on 2018/7/14.
//

#include "gtest/gtest.h"
#include "search_in_rotated_sorted_array.hpp"

using namespace search_in_rotated_sorted_array;

TEST(search_in_rotated_sorted_array, solution) {
    vector<int> vec {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(solution(vec, 0), 4);
    EXPECT_EQ(solution(vec, 3), -1);
}