//
// Created by eyeboy on 2018/7/15.
//
#include "gtest/gtest.h"
#include "find_first_and_last_position_of_element_in_sorted_array.hpp"

#include <iostream>

using namespace find_first_and_last_position_of_element_in_sorted_array;

TEST(find_first_and_last_position_of_element_in_sorted_array, solution) {
    vector<int> vec1 = {5, 7, 7, 8, 8, 10};

    vector<int> res1 = solution(vec1, 8);
    vector<int> res2 = solution(vec1, 6);

    std::cout << "";
}