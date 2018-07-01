//
// Created by eyeboy on 2018/7/1.
//
#include "gtest/gtest.h"
#include "merge_two_sorted_lists.hpp"

#include <iostream>

using namespace merge_two_sorted_lists;

TEST(merge_two_sorted_lists, solution) {
    ListNode *l1 = new ListNode(1);
    ListNode *node11 = new ListNode(2);
    ListNode *node12 = new ListNode(4);
    l1->next = node11;
    node11->next = node12;

    ListNode *l2 = new ListNode(1);
    ListNode *node21 = new ListNode(3);
    l2->next = node21;

    ListNode *res = solution(l1, l2);

    std::cout << "";
}
