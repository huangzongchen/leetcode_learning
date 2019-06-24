/*
 * @lc app=leetcode.cn id=148 lang=c
 *
 * [148] 排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void quick_sort(struct ListNode* begin, struct ListNode* end) {
    struct ListNode *prev = NULL;
    struct ListNode *scanner = NULL;
    struct ListNode *flag = NULL;
    scanner = begin->next;
    prev = begin;
    flag = begin->next;
    if (flag == end) {
        return;
    }
    while (scanner != end) {
        if (scanner->val < flag->val) {
            prev->next = scanner->next;
            scanner->next = begin->next;
            begin->next = scanner;
            scanner = prev->next;
        }
        else {
            prev = scanner;
            scanner = scanner->next;
        }
    }

    quick_sort(begin, flag);
    quick_sort(flag, end);
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode taghead = {0};
    taghead.next = head;
    quick_sort(&taghead, NULL);

    return taghead.next;
}



