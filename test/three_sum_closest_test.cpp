//
// Created by eyeboy on 2018/6/28.
//

#include "gtest/gtest.h"
#include "three_sum_closest.hpp"

using namespace three_sum_closest;

TEST(three_sum_closest, solution_1) {
    vector<int> test_case;
    test_case.push_back(-1);
    test_case.push_back(2);
    test_case.push_back(1);
    test_case.push_back(4);
    EXPECT_EQ(solution_1(test_case, 1), 2);
    EXPECT_EQ(solution_2(test_case, 1), 2);
}