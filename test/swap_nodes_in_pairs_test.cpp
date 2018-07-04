//
// Created by eyeboy on 2018/7/4.
//

#include "gtest/gtest.h"
#include "swap_nodes_in_pairs.hpp"

#include <iostream>

using namespace swap_nodes_in_pairs;

TEST(swap_nodes_in_pairs, solution_1) {
    ListNode *l = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);

    l->next = n1;
    n1->next = n2;
    //n2->next = n3;

    ListNode *result = solution_1(l);

    std::cout << "";
}