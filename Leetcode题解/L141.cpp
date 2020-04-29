// 判断链表中是否有环

/*
思路:
快慢指针, 快指针一次走两步, 慢指针一次走一步; 只要链表中环, 他俩就应会相遇; 因为两个指针会在环中绕
*/

#include<iostream>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

 bool hasCycle(ListNode *head) {
     ListNode* slow = head;
     ListNode* fast = head;
     while(fast && fast->next) {
         fast = fast->next->next;
         slow = slow->next;
         if (slow == fast) return true;
     }
     return false;
 }

int main() {

}
