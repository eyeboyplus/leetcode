//
// Created by eyeboy on 2018/8/30.
//

#include "gtest/gtest.h"
#include "merge_intervals.hpp"

#include <iostream>

using namespace merge_intervals;

TEST(merge_intervals, solution) {
    vector<Interval> vec1 = {Interval(2, 6), Interval(1,3), Interval(8,10), Interval(15, 18)};
    vector<Interval> res1 = solution(vec1);

    std::cout << "";
}