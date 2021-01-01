// 达到第N级有两种方法，从第N-1级向上1级，或者从第N-2级向上两级；由此不断向前推导，可将目标问题不断分解为规模更小、结构相同的子问题；求解目标问题时，子问题的解会被多次调用。因此这是一个动态规划问题

//推导方程：设F(N)表示达到N级的方法数，则F(N) = F(N-1) + F(N-2)

#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 定义数组dp存放子问题结果，并初始化前几项
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i ++) {
        dp[i] = dp[i -1] + dp[i - 2];
    }
    return dp[n];
    delete dp;
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n);
    
}