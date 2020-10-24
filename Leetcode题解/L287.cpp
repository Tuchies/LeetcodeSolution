/**
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 */

/**
 * 解题思路: 快慢指针, 环形链表的变式问题
 * 
 * 链表问题中: slow一次一步, fast一次两步, 有环的换两指针必定相遇
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    int t;
    vector<int> list;
    while (cin >> t) {
        cout << "t is :" <<t<<endl;
        list.push_back(t);
    }
    cout << findDuplicate(list);
    return 0;
}
