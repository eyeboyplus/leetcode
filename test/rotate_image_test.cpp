
//
// Created by eyeboy on 2018/8/7.
//
#include "gtest/gtest.h"
#include "rotate_image.hpp"

#include <iostream>

using namespace rotate_image;

TEST(rotate_image, solution) {
    vector<vector<int>> matrix1 = {
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
    };

    solution(matrix1);

    std::cout << "";
}