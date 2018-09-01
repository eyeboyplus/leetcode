//
// Created by eyeboy on 2018/8/31.
//
#include "gtest/gtest.h"
#include "insert_interval.hpp"

#include <iostream>

using namespace insert_interval;

TEST(insert_interval, solution) {
    vector<Interval> vec1 = {Interval(1, 3), Interval(6, 9)};
    vector<Interval> res1 = solution(vec1, Interval(2, 5));

    vector<Interval> vec2 = {Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16)};
    vector<Interval> res2 = solution(vec2, Interval(4, 8));

    std::cout << "";
}
