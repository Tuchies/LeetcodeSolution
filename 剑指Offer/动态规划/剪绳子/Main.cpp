// 剪绳子问题：将长为N的绳子剪短成整数长的M段，使得各段长度乘积最大(N,M均为正整数)
// 动态规划问题：当自顶向下难以发现规律的时候，就罗列最初的几种情况：
// 1.绳长为1，要保证整数长，不能剪，1*0
// 2.绳长为2，一种情况：1*1     
// 3.绳长为3，情况一：1*1*1；情况二：1*2    
// 4.绳长为4，情况一：1*1*1*1；情况二：1*3；情况三：1*2*1；情况四：2*2  
// 5.绳长为5，情况一：1*1*1*1*1；情况二：1*4；情况三：1*2*2；情况四：3*2；情况五：1*3*1

// 分析：绳长为4时，情况二包含了情况三；绳长为5时，情况二包含了情况三和情况五

// 设dp[i]存放的是绳长为i可得到的最大乘积；各个情况一舍去，dp[3] = dp[1]*dp[2]; dp[4] = MAX{dp[1]*dp[3], dp[2]*dp[2]}; dp[5] = MAX{dp[1]*dp[4], dp[2]*dp[3]}
// 进一步推导：dp[6] = MAX{dp[1]*dp[5], dp[2]*dp[4], dp[3]*dp[3]}....dp[n] = MAX{dp[1]*dp[n-1], dp[2]*dp[n-2], ....dp[i]*dp[n-i]},其中(1<= i <=n/2,为整数)

// 注意：需要初始化几个比较特殊的，绳长为1，2，3时，本身长度大于乘积

#include<iostream>

using namespace std;

int cutRope(int number) {
    if (number < 2) return 0;
    if (number == 2) return 1;
    if (number == 3) return 2;
    int *dp = new int[number+1];
    // 初始化特殊情况
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= number; i ++) {
        dp[i] = dp[1]*dp[i-1];
        for (int j = 2; j <= i/2; j++) {
            if(dp[i] < dp[j]*dp[i-j]) {
                dp[i] = dp[j]*dp[i-j];
            }
        }
    }
    return dp[number];
    delete dp;
}

int main() {
    int in;
    cin >> in;
    cout << cutRope(in) << endl;
    return 0;
}