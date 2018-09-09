//
// Created by eyeboy on 2018/9/9.
//

#include "gtest/gtest.h"
#include "minimum_path_sum.hpp"

using namespace minimum_path_sum;

TEST(minimum_path_sum, solution) {
    vector<vector<int>> grid1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    EXPECT_EQ(solution(grid1), 7);
}