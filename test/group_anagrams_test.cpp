//
// Created by eyeboy on 2018/8/8.
//
#include "gtest/gtest.h"
#include "group_anagrams.hpp"

#include <iostream>

using namespace group_anagrams;

TEST(group_anagrams, solution) {
    vector<string> vec1 = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res1 = solution(vec1);

    std::cout << "";
}
