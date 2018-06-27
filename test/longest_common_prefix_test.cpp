//
// Created by eyeboy on 2018/6/27.
//

#include "gtest/gtest.h"
#include "longest_common_prefix.hpp"

#include <vector>

using namespace longest_common_prefix;
using namespace std;

TEST(longest_common_prefix, solution) {

    vector<string> case1{"flower", "flow", "flight"};
    EXPECT_EQ(longestCommonPrefix(case1), "fl");

    vector<string> case2{"dog", "racecar", "car"};
    EXPECT_EQ(longestCommonPrefix(case2), "");

    vector<string> case3{"aca", "cba"};
    EXPECT_EQ(longestCommonPrefix(case3), "");

}