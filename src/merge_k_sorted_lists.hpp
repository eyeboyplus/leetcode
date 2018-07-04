//
// Created by eyeboy on 2018/7/2.
//

#ifndef LEETCODE_MERGE_K_SORTED_LISTS_HPP
#define LEETCODE_MERGE_K_SORTED_LISTS_HPP

#include <stack>
#include <climits>

using namespace std;

/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
    Example:
    Input:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    Output: 1->1->2->3->4->4->5->6
 */
namespace merge_k_sorted_lists {
    //Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    // O(k*n), O(1)
    // runtime error
    ListNode *solution_1(vector<ListNode*> &lists) {
        vector<ListNode*> ptrs;
        for(vector<ListNode*>::const_iterator iter = lists.cbegin();
                iter != lists.cend(); ++iter) {
            ptrs.push_back(*iter);
        }

        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(!ptrs.empty()) {
            int min = INT_MAX;
            int len = ptrs.size();
            if(len == 0)
                break;

            int min_idx = -1;
            for(int i = 0; i < len; ++i) {
                ListNode *ptr = ptrs[i];

                if(ptr == NULL) {
                    continue;
                } else {
                    if(ptr->val < min) {
                        min = ptr->val;
                        min_idx = i;
                    }
                }
            }
            p->next = ptrs[min_idx];
            p = p->next;
            ptrs[min_idx] = ptrs[min_idx]->next;

            for(int i=0; i<len; ++i) {
                if(ptrs[i] == NULL) {
                    ptrs.erase(ptrs.begin() + i);
                }
            }
        }

        ListNode *result = head->next;
        delete head;
        return result;
    }

    // 归并思想
    ListNode* solution_2(vector<ListNode*> &lists) {
        int len = lists.size();
        if(len == 0)
            return NULL;

        while (len > 1) {
            int i = 0, j = len - 1;

            while(i < j) {
                ListNode *l1 = lists[i];
                ListNode *l2 = lists[j];

                ListNode *head = new ListNode(-1);
                ListNode *p = head;
                while(l1 && l2) {
                    if(l1->val < l2->val) {
                        p->next = l1;
                        l1 = l1->next;
                    } else {
                        p->next = l2;
                        l2 = l2->next;
                    }
                    p = p->next;
                }

                if(l1) p->next = l1;
                if(l2) p->next = l2;

                lists[i] = head->next;
                delete head;

                i++; j--;
            }

            len = (len + 1) / 2;
        }
        return lists[0];
    }
}
#endif //LEETCODE_MERGE_K_SORTED_LISTS_HPP
