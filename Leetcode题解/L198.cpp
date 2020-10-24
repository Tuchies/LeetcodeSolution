// 动态规划问题：
// 当前位置N可盗窃的最大值，要么是N-1房子可盗窃的最大值，要么是N-2房子可盗窃的最大值 + 当前房子可盗窃的金额；
// 即dp(N) = MAX(dp(N-1), dp(N-2) + curNum)

//注意数组边界的处理

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int *dp = new int[nums.size()];
    dp[0] = nums[0];
    if(nums.size() == 1) return dp[0];
    dp[1] = max(nums[0], nums[1]);
    if (nums.size() == 2) return dp[1];
    for (int i = 2; i < nums.size(); i ++) {
        dp[i] = max(dp[i - 1], dp[i -2] + nums[i]);
    }
    return dp[nums.size() - 1];
    delete dp;
}

int main(){
    vector<int> list;
    string inp;
    cin >> inp;
    for (int i = 0; i < inp.size(); i++) {
        list.push_back(inp[i] - '0');
        //cout << list[i];
    }
    cout << rob(list);
}