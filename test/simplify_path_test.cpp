//
// Created by eyeboy on 2018/9/25.
//

#include "gtest/gtest.h"
#include "simplify_path.hpp"

using namespace simplify_path;

TEST(simplify_path, solution) {
    EXPECT_EQ(solution("/home/"), "/home");
    EXPECT_EQ(solution("/a/./b/../../c/"), "/c");
    EXPECT_EQ(solution("/a/../../b/../c//.//"), "/c");
    EXPECT_EQ(solution("/a//b////c/d//././/.."), "/a/b/c");
}