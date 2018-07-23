//
// Created by eyeboy on 2018/7/23.
//

#include "gtest/gtest.h"
#include "combination_sum_ii.hpp"

#include <iostream>

using namespace combination_sum_ii;

TEST(combination_sum_ii, solution) {
    vector<int> vec1 = {10, 1, 2, 7, 6, 1, 5};
    vector<int> vec2 = {2, 5, 2, 1, 2};
    vector<vector<int>> ret1 = solution(vec1, 8);
    vector<vector<int>> ret2 = solution(vec2, 5);

    std::cout << "";
}