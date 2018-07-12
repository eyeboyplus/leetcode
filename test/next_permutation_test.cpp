//
// Created by eyeboy on 2018/7/12.
//
#include "gtest/gtest.h"
#include "next_permutation.hpp"

#include <iostream>

using namespace next_permutation;

TEST(next_permutation, solution) {
    vector<int> vec1 {1, 2, 3};
    solution(vec1);

    vector<int> vec2 {1};
    solution(vec2);

    vector<int> vec3 {5, 1, 1};
    solution(vec3);

    std::cout << "";
}