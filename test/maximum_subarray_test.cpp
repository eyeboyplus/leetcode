//
// Created by eyeboy on 2018/8/15.
//
#include "gtest/gtest.h"
#include "maximum_subarray.hpp"

using namespace maximum_subarray;

TEST(maximum_subarray, solution) {
    vector<int> vec1 = {-2,1,-3,4,-1,2,1,-5,4};
    EXPECT_EQ(solution(vec1), 6);
}
