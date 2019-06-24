/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
return val: sum + add_val
val of hi 4 bit: add_val
val of low 4 bit : sum 
 */
unsigned char GetVal(struct ListNode* s1, struct ListNode* s2, int* pAddVal) {
    unsigned char Val = 0;
    if ((s1 == NULL) && (s2 != NULL)) {
        Val = (s2->val + *pAddVal ) % 10;
        *pAddVal = ((s2->val + *pAddVal) / 10);
        
    }
    else if ((s2 == NULL) && (s1 != NULL)) {
        Val = (s1->val + *pAddVal) % 10;
        *pAddVal =((s1->val + *pAddVal) / 10);
       
    }
    else if ((s1 != NULL) && (s2 != NULL)) {
        Val = (s1->val + s2->val + *pAddVal ) % 10;
        *pAddVal =((s1->val + s2->val + *pAddVal) / 10);
        
    }
    else {
        Val = *pAddVal;
        *pAddVal = 0;
        
    }
    return Val;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* Scanner1 = l1;
    struct ListNode* Scanner2 = l2;
    struct ListNode* NewNode = NULL;
    int Add_Val = 0;    
    int TmpVal = 0;
    struct ListNode* prev = NULL;
    struct ListNode head = {0};
    if (l1 == NULL && l2 != NULL) {
        return l2;
    }
    if (l1 != NULL && l1 == NULL) {
        return l1;
    }
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    prev = &head;
    while (Scanner1 != NULL || Scanner2 != NULL || Add_Val != 0) {
        NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        TmpVal = GetVal(Scanner1,Scanner2, &Add_Val);
        //Add_Val = (TmpVal & 0xf0) >> 4;
        NewNode->val =  TmpVal;
        NewNode->next = NULL;
        prev->next = NewNode;
        prev=NewNode;
        if (Scanner1 != NULL) {
            Scanner1 = Scanner1->next;     
        }   
        if (Scanner2 != NULL) {
            Scanner2 = Scanner2->next;
        }
        
    }

    return head.next;
}



