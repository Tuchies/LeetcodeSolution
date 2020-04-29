/*
反转链表, 返回新链表表头
*/

/*
思路:
遍历给定链表, 把val放在数组中, 倒序遍历数组, 构建新的链表
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* pHead) {
    // 边界检查
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    // 遍历链表
    vector<int> values;
    for(ListNode* temp = pHead; temp != NULL; temp = temp->next) {
        //cout << "the node wo got :  " << temp->val << endl;
        values.push_back(temp->val);
    }
    // 从数组倒序构建链表
    ListNode* ans = new ListNode(0);
    ListNode* p;
    p = ans;
    for (int i = values.size() - 1; i >= 0; i --) {
        //cout << "the value of i : " << values[i] << endl;
        ListNode* s = new ListNode(values[i]);
        p->next = s;
        p = s;
    }
    return ans->next;
}

int main() {
    /*------------从输入构建链表----------*/
    ListNode *head, *p;
	head = new ListNode(0);
	p = head;
	int x, cycle = 1;
	while (cycle) {
		cin >> x;
		if (x != 0) {
			ListNode* s = new ListNode(x);
			p->next = s;
			p = s;
		} else {
			cycle = 0;
			cout << "Input done! " << endl;
		}
	}
	p->next = NULL;
    cout << ReverseList(head->next)->val << endl;
    return 0;
}