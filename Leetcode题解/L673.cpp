/*
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
*/

#include<iostream>
#include<vector>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int n = nums.size();
    // 子序列至少包含他自己, 所以长度至少为1
    vector<int> dp(n,1);
    // 子序列至少包含他自己, 所以个数至少为1
    vector<int> counter(n,1);
    int maxs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // 第一次遇到
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    counter[i] = counter[j];
                } 
                // 再一次遇到
                else if (dp[j] + 1 == dp[i]) {
                    // 个数累加
                    counter[i] += counter[j];
                }
            }
        }
        maxs = max(maxs, dp[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxs) res += counter[i];
    }
    return res;
}

int main() {

}