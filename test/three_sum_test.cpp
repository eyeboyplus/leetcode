//
// Created by eyeboy on 2018/6/29.
//

#include "gtest/gtest.h"
#include "three_sum.hpp"

#include <iostream>

using namespace three_sum;

TEST(three_sum, solution) {
    vector<int> test_case{-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res1 = solution(test_case, 0);

    std::cout << "";
}