#include<iostream>
#include<vector>
using namespace std;

int main() {
    // 初始化一个dp数组
    vector<int> dp(37);
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 3;
    for (int i = 3; i < 37; i ++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    // 处理输入
    int day;
    cin >> day;
    vector<long long> rp(37);
    rp[day] = 0;
    for (int j = day; j > 0; j --) {
        rp[j-1] = (rp[j]+dp[j]) * 2;
    }
    cout << rp[0] << endl; // 所求是第一天的铁杆长
    return 0;
}


// 第i天的铁杆长度: rp[i] = rp[i-1]/2 - dp[i];
    // 反过来: rp[i-1] = (rp[i]+d[[i]]) * 2
    // 最后一天的铁杆长: rp[day] = rp[day-1]/2 - dp[day];