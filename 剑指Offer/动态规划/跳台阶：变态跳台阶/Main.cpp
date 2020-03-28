// 变态跳台阶问题：和原问题的不同在于，增加了一次跳上i级的特技(0<i<=N)
// 还是动态规划问题：同样到倒着推：到达N级的方式：从N-1向上一级，从N-2向上二级，从N-3向上三级.....从N-i向上i级；可设dp[i]存放的是到达i级的方法总数，dp[i] = dp[i-1] + dp[i-2] + ....+ dp[1] + 1, 初始化 dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4...

#include<iostream>

using namespace std;

int jumpFloorII(int number) {
    if(number < 1) return 0;
    int *dp = new int[number + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= number; i ++) {
        dp[i] = 1;
        for (int j = i-1; j >= 1; j--) {
            dp[i] += dp[j];
        }
    }
    return dp[number];
    delete dp;
}

int main() {
    int in;
    cin >> in;
    cout << jumpFloorII(in) << endl;
    return 0;
}