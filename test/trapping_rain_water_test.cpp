//
// Created by eyeboy on 2018/7/26.
//

#include "gtest/gtest.h"
#include "trapping_rain_water.hpp"

using namespace trapping_rain_water;

TEST(trapping_rain_water, solution) {

    vector<int> vec1 = {0,1,0,2,1,0,1,3,2,1,2,1};

    EXPECT_EQ(solution(vec1), 6);
}