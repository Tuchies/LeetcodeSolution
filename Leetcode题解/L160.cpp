/**
 * 寻找两个链表的第一个交点
 */

/**
 * 实现思路: 
 * 和判断链表有环的方法类似: 
 * 当较短的那个链表走完的时候, 就继续走长的链表
 * 同理, 当较长的链表走完的时候, 就继续走短的链表
 * 
 * 
 *  A和B两个链表长度可能不同，但是A+B和B+A的长度是相同的，所以遍历A+B和遍历B+A一定是同时结束。 如果A,B相交的话A和B有一段尾巴是相同的，所以两个遍历的指针一定会同时到达交点 如果A,B不相交的话两个指针就会同时到达A+B（B+A）的尾节点
 * 
 * 也就是说: 如果相交了, 会在交点处有 pa = pb; 不相交则会同时达到末尾的NULL
 */

#include<iostream>
using namespace std;
struct ListNode
{
    int  val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return (ListNode*) NULL;
    ListNode* pa = headA;
    ListNode* pb = headB;
    while (pa != pb)
    {
        if (pa!=NULL) pa = pa->next;
        else pa = headB;

        if (pb!=NULL) pb = pb->next;
        else pb = headA;
    }
    return pa;
}

int main() {
    ListNode* a = new ListNode(0);
    ListNode* a1 = new ListNode(1);
    ListNode* b = new ListNode(7);
    ListNode* b1 = new ListNode(8);
    ListNode* b2 = new ListNode(9);
    ListNode* m1 = new ListNode(100);
    ListNode* m2 = new ListNode(200);
    a->next = a1;
    a1->next = m1;
    m1->next = m2;
    b->next = b1;
    b1->next = b2;
    b2->next = m2;
    cout << getIntersectionNode(a, b)->val;
    return 0;
}

