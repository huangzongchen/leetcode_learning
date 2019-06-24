/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* s = head;
    struct ListNode even_head = {0};
    struct ListNode odd_head = {0};
    struct ListNode* prev_even = NULL;
    struct ListNode* prev_odd = NULL;
    int flag = 1;
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    odd_head.next = head;
    even_head.next = head->next;
    prev_even = &even_head;
    prev_odd = &odd_head;

    while (s != NULL) {
        if (flag % 2 == 1) {
            prev_odd->next = s;
            prev_odd = s;
            s = s->next;
        }
        else {
            prev_even->next = s;
            prev_even = s;
            s = s->next;
        }
        flag += 1;
    }
    prev_even->next = NULL;
    prev_odd->next = even_head.next;

    return odd_head.next;
}



