//
// Created by eyeboy on 2018/9/5.
//

#ifndef LEETCODE_ROTATE_LIST_HPP
#define LEETCODE_ROTATE_LIST_HPP

/**
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
Example 1:
    Input: 1->2->3->4->5->NULL, k = 2
    Output: 4->5->1->2->3->NULL
    Explanation:
    rotate 1 steps to the right: 5->1->2->3->4->NULL
    rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:
    Input: 0->1->2->NULL, k = 4
    Output: 2->0->1->NULL
    Explanation:
    rotate 1 steps to the right: 2->0->1->NULL
    rotate 2 steps to the right: 1->2->0->NULL
    rotate 3 steps to the right: 0->1->2->NULL
    rotate 4 steps to the right: 2->0->1->NULL
 */
namespace rotate_list {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* solution(ListNode *node, int k) {
        int size = 0;

        ListNode *p = node;
        for(;p != NULL; size ++, p = p->next);

        if(size == 0 || size == 1)
            return node;

        int remainder = k % size;

        ListNode head(0);
        head.next = node;
        if(remainder != 0) {
            ListNode *parent = &head;
            for(int i = size - remainder; i > 0; i--)
                parent = parent->next;
            ListNode *target = parent->next;
            parent->next = NULL;

            ListNode *next = head.next;
            head.next = target;
            while(target->next != NULL) target = target->next;
            target->next = next;
        }

        return head.next;
    }
}

#endif //LEETCODE_ROTATE_LIST_HPP
