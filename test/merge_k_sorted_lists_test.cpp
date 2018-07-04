//
// Created by eyeboy on 2018/7/2.
//

#include "gtest/gtest.h"
#include "merge_k_sorted_lists.hpp"

#include <iostream>

using namespace merge_k_sorted_lists;

TEST(merge_k_sorted_lists, solution_1) {

    ListNode *l1 = new ListNode(1);
    ListNode *n11 = new ListNode(4);
    ListNode *n12 = new ListNode(5);
    l1->next = n11;
    n11->next = n12;

    ListNode *l2 = new ListNode(1);
    ListNode *n21 = new ListNode(3);
    ListNode *n22 = new ListNode(4);
    l2->next = n21;
    n21->next = n22;

    ListNode *l3 = new ListNode(2);
    ListNode *n31 = new ListNode(6);
    l3->next = n31;

    vector<ListNode*> vec = {l1, l2, l3};

    ListNode *res = solution_1(vec);

    std::cout << "";
}

TEST(merge_k_sorted_lists, solution_2) {
    ListNode *l1 = new ListNode(1);
    ListNode *n11 = new ListNode(4);
    ListNode *n12 = new ListNode(5);
    l1->next = n11;
    n11->next = n12;

    ListNode *l2 = new ListNode(1);
    ListNode *n21 = new ListNode(3);
    ListNode *n22 = new ListNode(4);
    l2->next = n21;
    n21->next = n22;

    ListNode *l3 = new ListNode(2);
    ListNode *n31 = new ListNode(6);
    l3->next = n31;

    vector<ListNode*> vec = {l1, l2, l3};

    ListNode *res = solution_2(vec);

    std::cout << "";
}