//
// Created by eyeboy on 2018/7/6.
//

#include "gtest/gtest.h"
#include "remove_element.hpp"

using namespace remove_element;

TEST(remove_element, solution) {
    vector<int> nums1 {3, 2, 2, 3};
    EXPECT_EQ(solution(nums1, 3), 2);
    vector<int> nums2 {0,1,2,2,3,0,4,2};
    EXPECT_EQ(solution(nums2, 2), 5);
    vector<int> nums3 {0};
    EXPECT_EQ(solution(nums3, 0), 0);
}