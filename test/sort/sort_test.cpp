//
// Created by eyeboy on 2018/9/2.
//
#include "gtest/gtest.h"
#include "base/quick_sort.hpp"
#include "base/insertion_sort.hpp"

using namespace base;

TEST(sort, quick_sort) {
    vector<int> vec1 = {1, 4, 5, 2, 3, 7};
    quick_sort(vec1, 0, vec1.size() - 1);

    vector<int> vec2 = {1, 4, 5, 2, 3, 7};
    insertion_sort(vec2, 0, vec2.size() - 1);

    std::cout << "";
}
