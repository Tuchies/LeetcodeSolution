// 用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 
// 因为宽度已经限制，只有长度变化，随着规模增大，一定会重复调用小规模问题的结果，是动态规划问题
// 假设要覆盖的矩形是2*5，第一块小矩形有两种放置方法：一是竖着放，则右侧就会变成2*4的矩形，问题转换；二是横着放，则下侧也必须横放一块小矩形（否则不满足宽），此时右侧变成2*3的矩形
// 那么可设：dp[i]存放的是长为i的矩形的方法总数，有dp[i] = dp[i-1] + dp[i-2]，初始化dp[0]=0, dp[1]=1, dp[2]=2, dp[3]=3；最终返回dp[n]

#include<iostream>

using namespace std;

int rectCover(int number) {
    if(number < 1) return 0;
    int *dp = new int[number+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= number; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[number];
    delete dp;
}

int main() {
    int in;
    cin >> in;
    cout << rectCover(in) << endl;
    return 0;
}