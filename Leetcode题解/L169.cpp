/**
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素
 */

/**
 * 解题思路: 
 * 分治法: 参见leetcode的官方题解的分治解法:
 * 
 * 结论: 如果a是数组num[]的众数, 那么将num一分为二, a至少是一部分的众数
 * 证明(反证法): 假设 a 既不是左半部分的众数，也不是右半部分的众数，那么 a 出现的次数少于 left / 2 + right / 2 次。由于 left / 2 + right / 2 <= (left + right) / 2，说明 a 也不是数组 nums 的众数，因此出现了矛盾。所以这个结论是正确的
 * 
 * 思路: 将数组一分为二, 分别求出左边部分的众数aLeft和右边部分的众数aRight, 然后在两者中选出正确的众数即可
 */

#include<iostream>
#include<vector>
using namespace std;

// 统计众数的出现次数, num是传入的众数
int countInRange(vector<int>& nums, int num, int lo, int hi) {
    int count = 0;
    // 遍历数组切片, 统计该切片中num的出现次数
    for (int i = lo; i <= hi; i++) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElementRec(vector<int>& nums, int lo, int hi) {
    // 只有一个元素的情况, nums.size()为1
    if (lo == hi) {
        return nums[lo];
    }

    // 递归的把数组分为两部分
    int mid = (hi-lo)/2 + lo;
    int left = majorityElementRec(nums, lo, mid); // 左半部分
    int right = majorityElementRec(nums, mid+1, hi); // 右半部分

    // 如果两部分众数相同
    if (left == right) {
        return left;
    }

    // 不相同, 就统计两个众数的出现次数, 返回多次的那个
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}

int majorityElement(vector<int> &nums) {
    return majorityElementRec(nums, 0, nums.size()-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i ++) {
        cin >> n;
        list[i] = n; 
    }
    cout << majorityElement(list);
    return 0;
}
