// 删除链表的倒数第N个节点, 返回链表头节点

/**
 * 快慢双指针都指向哨兵节点, 快的先走, 直到两指针相距为N, 然后俩一起走
 * 快的到头之时, 慢的就指向目标节点
 */ 

#include<iostream>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    int distance = 0;
    while (fast->next) {
        if (distance < n) {
            fast = fast->next;
            distance ++;
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // 循环结束就找到了目标节点, delete it!
    slow->next = slow->next->next;
    return dummy->next;
}
