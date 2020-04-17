// 两两交换链表中的节点: 双指针, 使用dummy节点串联

/**
 * 思路:
 * 使用双指针pre, be分别指向相邻的前后俩节点
 * 
    引入哨兵节点dummy, 使得dummy先指向后边的be, 再指向前边的pre, 注意在中间的过程中, 保持和后续节点的联系
 */ 

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // 串联指针
    ListNode* temp = dummy;
    
    while (temp->next != NULL && temp->next->next != NULL){ 
        ListNode* pre = temp->next; 
        ListNode* be = temp->next->next;
        // 1.将后边节点放在前
        temp->next = be; 
        // 2.维系和后续节点的联系
        pre->next = be->next; 
        // 3.将原先在前的节点放在后
        be->next = pre; // 完成交换
        // 4.移动串联指针, 预备下一组交换
        temp = pre; 
    } 
    return dummy->next;
}