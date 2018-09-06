//
// Created by eyeboy on 2018/9/5.
//

#include "gtest/gtest.h"
#include "rotate_list.hpp"

using namespace rotate_list;

TEST(rotate_list, solution) {
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n0.next = &n1;
    n1.next = &n2;
    ListNode *res1 = solution(&n0, 4);

    std::cout << "";
}