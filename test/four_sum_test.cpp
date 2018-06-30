//
// Created by eyeboy on 2018/6/29.
//
#include "gtest/gtest.h"
#include "four_sum.hpp"

#include <iostream>

using namespace four_sum;

TEST(four_sum, solution) {
    vector<int> test_case {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res1 = solution(test_case, 0);
    std::cout << "" << std::endl;
}