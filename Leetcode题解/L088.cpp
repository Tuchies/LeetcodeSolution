// “合并有序链表”问题的变形，使用双指针从前往后遍历，结果放在新数组中，最后再赋值给nums1

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1[i] >= nums2[j]) {
            temp.push_back(nums2[j ++]);
        } else {
            temp.push_back(nums1[i ++]);
        }
    }
    if (i < m) {
        for (int x = i; x < m; x ++) {
            temp.push_back(nums1[x]);
        }
    } else{
        for (int x = j; x < n; x ++) {
            temp.push_back(nums2[x]);
        }
    }
    nums1 = temp;
}

int main() {
    vector<int> nums1, nums2;
    string inp1, inp2;
    cin >> inp1 >> inp2;
    int m = inp1.size(), n = inp2.size();
    for (int i = 0; i < m; i ++) {
        nums1.push_back(inp1[i] - '0');
    }
    for (int i = 0; i < m; i ++) {
        nums2.push_back(inp2[i] - '0');
    }
    merge(nums1, m, nums2, n);
}