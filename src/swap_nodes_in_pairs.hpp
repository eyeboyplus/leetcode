//
// Created by eyeboy on 2018/7/4.
//

#ifndef LEETCODE_SWAP_NODES_IN_PAIRS_HPP
#define LEETCODE_SWAP_NODES_IN_PAIRS_HPP

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
    Example:
    Given 1->2->3->4, you should return the list as 2->1->4->3.
    Note:
    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
namespace swap_nodes_in_pairs {
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    // O(n), O(1)
    ListNode *solution_1(ListNode *head) {
        ListNode *h = new ListNode(-1);
        h->next = head;

        ListNode *prior = h;
        while(prior->next && prior->next->next) {
            ListNode *p1 = prior->next;
            ListNode *p2 = prior->next->next;

            ListNode *next = p2->next;

            prior->next = p2;
            p2->next = p1;
            p1->next = next;
            prior = p1;
        }

        ListNode *result = h->next;
        delete h;

        return result;
    }
}

#endif //LEETCODE_SWAP_NODES_IN_PAIRS_HPP
