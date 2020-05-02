/*
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/

/*
借用set结构, 把链表1的节点都放进去; 遍历链表2, 返回第一个添加出错的节点
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
      // 边界检查
      if (pHead1 == NULL || pHead2 == NULL) {
          return (ListNode*)NULL;
      }
      ListNode* ans = (ListNode*)NULL;
      // 放入链表1的节点
      set<ListNode*> sets;
      ListNode* p1 = pHead1;
      while(p1->next != NULL) {
          sets.insert(p1);
          p1 = p1->next;
      }
      // 遍历链表2
      ListNode* p2 = pHead2;
      while(p2->next != NULL) {
          pair<set<ListNode*>::iterator, bool> temp = sets.insert(p2);
          // 插入失败
          if (!temp.second) {
              ans = p2;
              break;
          }
      }
      return ans;
}

int main() {
    int n;
    vector<int> list1, list2;
    while(cin >> n) {
        list1.push_back(n);
    }
    int m;
    while(cin >> m) {
        list2.push_back(m);
    }
    ListNode* head1,* p1,* head2,* p2;
    head1->val = 0;
    head2->val = 0;
    p1 = head1;
    p2 = head2;
    // 构建链表1
    for (int i = 0; i < list1.size(); i ++) {
        ListNode* temp = new ListNode(list1[i]);
        p1 = temp;
        p1 = p1->next;
    }
    p1->next = NULL;
    // 构建链表2
    for (int i = 0; i < list2.size(); i ++) {
        ListNode* temp = new ListNode(list2[i]);
        p2 = temp;
        p2 = p2->next;
    }
    p2->next = NULL;
    cout << FindFirstCommonNode(head1->next, head2->next)->val << endl;
    return 0;
}