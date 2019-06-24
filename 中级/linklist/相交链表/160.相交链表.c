/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* s1;
    struct ListNode* s2;
    int lenA = 0;
    int lenB = 0;
    int delta = 0;
    int len = 0;
    int flag = 0; /* 0:A, 1:B */
    struct ListNode* s = NULL;
    
    s1 = headA;
    s2 = headB;

    while (s1 != NULL) {
        lenA ++;
        s1 = s1->next;
    }
    while (s2 != NULL) {
        lenB ++;
        s2 = s2->next;
    }

    if (lenA > lenB) {
        flag = 0;
        s = headA;
        s2 = headB;
        delta = lenA - lenB;
    }
    else {
        flag = 1;
        s = headB;
        s1 = headA;
        delta = lenB - lenA;
    }
    
    
    while (delta > 0) {
        s = s->next;
        delta = delta - 1;
    }

    if (flag == 0) {
        s1 = s;
    }else {
        s2 = s;
    }

    while (s1 != s2) {
        if (s1 != NULL){
            s1 = s1->next;
        }
        if (s2 != NULL){
            s2 = s2->next;
        }
    }
    return s1;
}

