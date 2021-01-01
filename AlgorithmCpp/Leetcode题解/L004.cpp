/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
*/

/*
思路: 合并两个有序数组, 然后找中位数
*/

#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> list;
    if (m == 0 && n == 0) {
        return 0.0;
    } 
    
    // 双指针遍历合并
    int i = 0, j = 0;
    for(; i < m && j < n; ) {
        // 找出小的, 把它的指针后移
        if (nums1[i] <= nums2[j]) {
            list.push_back(nums1[i]);
            i ++;
        } else {
            list.push_back(nums2[j]);
            j ++;
        }
    }
    // 对于长的那个数组, 把没放完的元素放完
    if (i < m) {
        for(int x = i; x < m; x++) {
            list.push_back(nums1[x]);
        }
    } 
    if (j < n) {
        for(int x = j; x < n; x++) {
            list.push_back(nums2[x]);
        }
    }
    for (int i = 0; i < list.size(); i++) {
        cout << "shuzu ==="<< list[i] << endl;
    }
    double ans = 0.0;
    if (list.size() % 2 == 0) {
        //cout << list.size() << "----" << endl;
        ans = (list[list.size()/2] + list[list.size()/2-1])/2.0;
    } else {
        //cout << list.size()/2;
        ans = list[list.size()/2];
    }
    return ans;
}

int main() {
    int count1, count2;
    cin >> count1 >> count2;
    vector<int> nums1(count1);
    vector<int> nums2(count2);
    for (int i = 0; i < count1; i ++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < count2; i ++) {
        cin >> nums2[i];
    }
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}


















