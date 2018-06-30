//
// Created by eyeboy on 2018/6/30.
//
#include "gtest/gtest.h"
#include "remove_n_th_node_from_end_of_list.hpp"

#include <iostream>

using namespace remove_nth_node_from_end_of_list;

class RemoveNthNodeFromEndOfListTest : public testing::Test {
protected:
    void SetUp() override {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        ListNode *node5 = new ListNode(5);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        root = node1;
    }

    void TearDown() override {
    }

    ListNode *root;
};

TEST_F(RemoveNthNodeFromEndOfListTest, solution_1_0) {
    ListNode *node = solution_1(root, 2);
    std::cout << "";
}

TEST_F(RemoveNthNodeFromEndOfListTest, solution_1_1) {
    ListNode *node = solution_1(root, 5);
    std::cout << "";
}


TEST_F(RemoveNthNodeFromEndOfListTest, solution_2_0) {
    ListNode *node = solution_2(root, 2);
    std::cout << "";
}

TEST_F(RemoveNthNodeFromEndOfListTest, solution_2_1) {
    ListNode *node = solution_2(root, 5);
    std::cout << "";
}