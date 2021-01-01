// 合并两个升序链表: 

/**
 * 思路: 
 * 引入哨兵节点, 便于返回结果, 引入串联指针, 用于将两个链表"穿起来"
 * 
 * 将L1和L2的当前值比较, 小的那个被指针穿起来, 然后向后移动; 重复比较, 直到某个链表到头
 */ 

#include<iostream>


struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    
    while (l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            temp->next = l1;
            // 小的移动
            l1 = l1->next;
        } else{
            temp->next = l2;
            // 小的移动
            l2 = l2->next; 
        }
        // 串联针也要移动
        temp = temp->next;
    }
    // 一次性穿起来剩下的那点
    if(l1 != NULL)
        temp->next = l1;
    else 
        temp->next = l2;
    return dummy->next;
}