//
// Created by eyeboy on 2018/9/7.
//

#include "gtest/gtest.h"
#include "unique_paths_ii.hpp"

using namespace unique_paths_ii;

TEST(unique_paths_ii, solution) {
    vector<vector<int>> matrix1 = {  
        {0,1},
    };

    EXPECT_EQ(solution(matrix1), 0);
}