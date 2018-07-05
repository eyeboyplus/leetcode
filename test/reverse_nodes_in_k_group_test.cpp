//
// Created by eyeboy on 2018/7/5.
//

#include "gtest/gtest.h"
#include "reverse_nodes_in_k_group.hpp"

#include <iostream>

using namespace reverse_nodes_in_k_group;

TEST(reverse_nodes_in_k_group, solution_1) {

    ListNode *root = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);
    ListNode *n4 = new ListNode(5);

    root->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode *res1 = solution_1(root, 3);

    std::cout << "";
}
