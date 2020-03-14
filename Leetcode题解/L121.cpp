// 买卖股票的最佳时机：即所求为数组中差值最大的两个元素，返回后者的 下标+1
// 思路转换：以当前数i为基点（后续的数必须比他大），要使 n-i的差值最大，只需要 i+n的和最大；由此，该问题可以视为一个 “离散化的最大连续子数组和”问题
// 转换方程：设dp[i]存放与当前元素组成的最大和，i是数组下标，第i+1天卖出利润最大；初始化dp0=num[0],dp1=[num[0]+num[1]],dp2=MAX{num[1]+num[2], num[0]+num[2]}=MAX{num[0], num[1]}, dp[3]=MAX{num[0], num[1], num[2]}=MAX{dp[2], num[2]}
// 由此推导出：dp[i] = MAX{dp[i-1], num[i-1]}

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    // TODO
}

int main() {
    vector<int> in;
    in.push_back(7);
    in.push_back(1);
    in.push_back(5);
    in.push_back(3);
    in.push_back(3);
    
    cout << maxProfit(in) << endl;
    return 0;
}