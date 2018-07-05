//
// Created by eyeboy on 2018/7/5.
//

#ifndef LEETCODE_REVERSE_NODES_IN_K_GROUP_HPP
#define LEETCODE_REVERSE_NODES_IN_K_GROUP_HPP


/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
    k is a positive integer and is less than or equal to the length of the linked list.
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
    Example:
    Given this linked list: 1->2->3->4->5
    For k = 2, you should return: 2->1->4->3->5
    For k = 3, you should return: 3->2->1->4->5
    Note:
    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.
 */
namespace reverse_nodes_in_k_group {
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* solution_1(ListNode *l, int k) {
        ListNode head(-1);

        ListNode *p1 = l;           // traverse pointer
        ListNode *p2 = &head;       // result pointer

        while(p1) {
            ListNode *group_start = NULL, *group_end = NULL;
            group_start = p1;

            for(int i = 1; i < k; ++i) {
                if(p1->next == NULL) {
                    p2->next = group_start;
                    return head.next;
                }
                p1 = p1->next;
            }
            group_end = p1;
            p1 = p1->next;

            ListNode *tail = group_start;
            while(group_start != group_end) {
                ListNode *next = group_start->next;
                group_start->next = p2->next;
                p2->next = group_start;

                group_start = next;
            }
            group_start->next = p2->next;
            p2->next = group_start;
            p2 = tail;
        }

        return head.next;
    }
}

#endif //LEETCODE_REVERSE_NODES_IN_K_GROUP_HPP
