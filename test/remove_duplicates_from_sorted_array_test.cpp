//
// Created by eyeboy on 2018/7/6.
//
#include "gtest/gtest.h"
#include "remove_duplicates_from_sorted_array.hpp"

#include <iostream>

using namespace remove_duplicates_from_sorted_array;

TEST(remove_duplicates_from_sorted_array, solution) {
    vector<int> nums1 {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    EXPECT_EQ(solution(nums1), 5);
    vector<int> nums2 {1, 1, 2};
    EXPECT_EQ(solution(nums2), 2);

    std::cout << "";
}