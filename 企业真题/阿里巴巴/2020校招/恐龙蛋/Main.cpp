/**
 * 给 n 个恐龙蛋及恐龙蛋的大小，按从大到小排列，
 * 第 i 个恐龙蛋每天增大 i，
 * 问最少几天会出现两个同样大小的恐龙蛋。
 */

/**
 * 举例分析: 给定数组[5,3,2,1]
 * 第一天: [6,5,5,5]
 * 第二天: [7,7,8,9]
 * 
 * 相邻元素的差值, 就是这两个元素追平的天数...
 * 也就是求相邻元素的最小值
 */

#include<iostream>
#include<vector>
using namespace std;

void printDay(vector<long long> list, long long n) {
    long long minDay = 0;
    long long day;
    // 寻找相邻元素的最小值
    for (long long i = 2; i <= n; i ++ ) {
        day = list[i-1] - list[i];
        minDay = min(minDay, day);
    }
    printf("%lld",minDay);
}

int main() {
    long long n;
    scanf("%lld",&n);
    vector<long long> list(n+1);
    list[0] = -1;
    // 获取输入用例
    for (long long i = 1; i <= n; i ++) {
        scanf("%lld",&list[i]);
        // 如果有一样的 直接输出0
        if (list[i] + 1 == list[i-1]) {
            printf("0");
            goto exit;
        }
    }
    printDay(list, n);
    exit: return 0;
}
