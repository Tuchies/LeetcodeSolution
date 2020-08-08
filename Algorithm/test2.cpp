#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool judgep(long long m) {
    if (m == 0 || m == 1) return false;
}

void printCount(vector<long long>& list, int n) {
    // dp是数组中前i个元素拆分的质数总和
    // 对于元素i, 可以拆, 也可以不拆: dp[i] = cur_count(list[i]) + dp[i-1] + 1/0+list[i]
}

int main() {
    int n;
    long long tmp;
    scanf("%d",&n);
    vector<long long> list(n);
    for (int i = 0; i < n; i ++) {
        scanf("%lld",&list[i]);
    }
    printCount(list, n);
    return 0;
    return 0;
}