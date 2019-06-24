/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* scanner1 = NULL;
    struct ListNode* scanner2 = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* prev1 = NULL;
    struct ListNode head1 = {0};
    int i =0;
    if (listsSize == 0)  {
        return NULL;
    }

    head1.next = lists[0];
    for (i = 1; i < listsSize; i++) {
       
        scanner2 = (lists[i]);
        while (scanner2 != NULL) {
            scanner1 = head1.next;
            prev1 = &head1;
            temp = scanner2->next;
            while (scanner1 != NULL) {
                if (scanner2->val <= scanner1->val) {
                    prev1->next = scanner2;
                    scanner2->next = scanner1;
                    break;
                }
                prev1 = scanner1;
                scanner1 = scanner1->next;
            }
            if (scanner1 == NULL) {
                prev1->next = scanner2;   
                prev1->next->next = NULL;                            
            }
            scanner2 = temp;               
        }
    }    

    return head1.next;
}



