// 删除链表中的重复元素: 双指针解决, 不借助其他数据结构

/**
 * 思路:
 * 快慢两指针从前往后遍历, 比较相邻元素, 若是值相等, 就去掉该节点; 否则, 快慢两指针向后移动一格; 直到链表末尾
 */ 

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *fast, *slow;
    // 空指针检查
    if(head != NULL && head->next != NULL) {
        fast = dummy->next->next;
        slow = dummy->next;
    } else {
        return head;
    }

    while(slow->next != NULL) {
        if (fast->val == slow->val) {
            ListNode* temp;
            // 使slow连接后续组第一个节点
            slow->next = fast->next;
            // 去掉fast指向的重复节点
            fast->next = temp;
            // 使fast重新指向后续组的第二个节点
            fast = slow->next;
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return dummy->next;
}    