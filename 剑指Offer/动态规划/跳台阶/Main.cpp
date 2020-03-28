//跳台阶问题：问到N级台阶有多少种方法
// 典型的动态规划问题：倒着推，到达N有两种情况，一是从N-1向上一级，二是从N-2向上两级；可设dp[i]存放的是到达第i级台阶的方法数，则dp[i] = d[i-1] + dp[i-2]；初始化dp[0]=0, dp[1]=1, dp[2]=2, dp[3]=3;

#include<iostream>

using namespace std;

int jumpFloor(int number) {
    if (number < 1) return 0;
    int *dp = new int[number+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= number; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[number];
    delete dp;
}

int main() {
    int in;
    cin >> in;
    cout << jumpFloor(in) << endl;
    return 0;
}