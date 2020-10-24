// “198打家劫舍”问题的同类题型；通过比较当前阶段的和与下一个元素的大小，来标记最大和
// 基于上述思路，可定义max变量，max用于标记最大和，最终返回；再定义dp[]数组，存放各阶段的最大和；其中，每个阶段的阶段的最大和也是当前阶段问题的最优解，符合最优子结构性质；状态方程为：dp[i] = max{dp[i - 1] + nums[i], nums[i]}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int *dp = new int[nums.size()];
    dp[0] = nums[0];
	int max = nums[0];
	for (int i = 1; i < nums.size(); i++) {
	    dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);	
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	return max;
    delete dp;
}

int main(){
    string inp;
    cin >> inp;
    vector<int> digits;
    for (int i = 0; i < inp.size(); i ++) {
        digits.push_back(inp[i] - '0');
    }
    cout << maxSubArray(digits) << endl;
}