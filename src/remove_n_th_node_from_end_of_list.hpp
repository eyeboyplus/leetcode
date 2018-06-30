//
// Created by eyeboy on 2018/6/30.
//

#ifndef LEETCODE_REMOVE_N_TH_NODE_FROM_END_OF_LIST_HPP
#define LEETCODE_REMOVE_N_TH_NODE_FROM_END_OF_LIST_HPP

/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
    Example:
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note: Given n will always be valid.
 */
namespace remove_nth_node_from_end_of_list {
    //Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    /**
     * 1. 遍历整个链表，统计单向链表长度len
     * 2. 根据len和n，找到要删除的节点的父节点
     * 3. 常规删除链接节点操作
     * Notes: 删除第一个节点特殊处理
     */
    ListNode* solution_1(ListNode* head, int n) {
        int len = 0;
        ListNode *p = head;
        while(p) {
            len ++;
            p = p->next;
        }

        ListNode *result = NULL;

        int diff = len - n;
        if(diff == 0) {
            result = head->next;
            delete head;
        } else {
            p = head;
            while(diff > 1) {
                p = p->next;
                diff --;
            }

            ListNode *parent = p;
            ListNode *target = parent->next;
            parent->next = target->next;
            delete target;
            result = head;
        }

        return result;
    }

    /**
     * 仅遍历一次链表
     * 0. 初始化：指针ptr为链表头，parent，target为NULL
     * 1. 指针ptr先向前移动 n
     * 2. 判断ptr是否为NULL, 如果为NULL，则delete head ,返回head->next
     * 3. ptr不为空，target指向链表头
     * 4. ptr,target不断向后移动，其中parent记录target的父节点，直到ptr为NULL
     * 5. 此时target所指向的节点就是要删除的节点，parent为target节点的父节点
     */
    ListNode *solution_2(ListNode *head, int n) {
        ListNode *ptr = head;
        ListNode *parent = NULL;
        ListNode *target = NULL;

        for(int i = 0; i < n; ++i) {
            ptr = ptr->next;
        }

        ListNode *result = NULL;
        if(ptr == NULL) {
            result = head->next;
            delete head;
            return result;
        }

        target = head;
        while(ptr != NULL) {
            ptr = ptr->next;
            parent = target;
            target = target->next;
        }

        parent->next = target->next;
        delete target;
        result = head;

        return result;
    }
}

#endif //LEETCODE_REMOVE_N_TH_NODE_FROM_END_OF_LIST_HPP
