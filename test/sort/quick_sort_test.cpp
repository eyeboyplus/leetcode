//
// Created by eyeboy on 2018/9/2.
//
#include "gtest/gtest.h"
#include "sort/quick_sort.hpp"

using namespace sort;

TEST(sort, quick_sort) {
    vector<int> vec1 = {1, 4, 5, 2, 3, 7};
    quick_sort(vec1, 0, vec1.size() - 1);

    std::cout << "";
}
