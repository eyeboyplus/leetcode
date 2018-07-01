//
// Created by eyeboy on 2018/7/1.
//

#ifndef LEETCODE_MERGE_TWO_SORTED_LISTS_HPP
#define LEETCODE_MERGE_TWO_SORTED_LISTS_HPP

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
    Example:
    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4
 */
namespace merge_two_sorted_lists {

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* solution(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;

    ListNode *head = new ListNode(0);
    ListNode *p = head;

    while(p1 && p2) {
        int value = 0;
        if(p1->val < p2->val) {
            value = p1->val;
            p1 = p1 ->next;
        } else {
            value = p2->val;
            p2 = p2->next;
        }
        ListNode *node = new ListNode(value);
        p->next = node;
        p = p->next;
    }

    while(p1) {
        ListNode *node = new ListNode(p1->val);
        p->next = node;
        p = p->next;
        p1 = p1->next;
    }
    while(p2) {
        ListNode *node = new ListNode(p2->val);
        p->next = node;
        p = p->next;
        p2 = p2->next;
    }

    ListNode *result = head->next;
    delete head;

    return result;
}
}

#endif //LEETCODE_MERGE_TWO_SORTED_LISTS_HPP
