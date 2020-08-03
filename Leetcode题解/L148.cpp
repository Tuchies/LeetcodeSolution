/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 public ListNode sortList(ListNode head) {
    if (head == null || head.next == null)
        return head;
    ListNode fast = head.next, slow = head;
    // 双指针法找到断点
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // 断开链表
    ListNode tmp = slow.next;
    slow.next = null;
    // 递归的断开链表, 直到子链表仅有一个节点
    ListNode left = sortList(head);
    ListNode right = sortList(tmp);
    // 开辟新的链表
    ListNode h = new ListNode(0);
    ListNode res = h;
    // 合并两个有序链表
    while (left != null && right != null) {
        if (left.val < right.val) {
            h.next = left;
            left = left.next;
        } else {
            h.next = right;
            right = right.next;
        }
        h = h.next;
    }
    h.next = left != null ? left : right;
    return res.next;
}
