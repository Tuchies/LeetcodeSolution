/*
给定一个数x，数据对 (a, b)使得a ^ b ^ x能达到最大，求使|a - b|最小的方案总数有多少。
x,a,b的范围都是0 - （2^31 次方-1）
*/

/**
 * 题目翻译: a ^ b ^ x能达到最大, 也就是达到INT_MAX, 也就是除了符号位, 其余全是1(二进制)
 * 
 * 从二进制的角度出发, 
 * 如果x的某一位是1,那么ab的对应位必须相同, 是1或0为所谓, 因为: 1^1^1=1; 1^0^0=0; 方案*2
 * c如果x的某一位是0,那么ab应当一个1,一个是0; 不能取到最小, 方案不变
 */

#include<iostream>
using namespace std;
typedef long long LL;
 
int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        LL res = 2;
        // 二进制,32位
        // x >> i, 就是遍历x的二进制位
        for (int i = 0; i < 32; ++i) {
            // 都为1, 才为1; 如果x的某一位是1
            if ((x >> i) & 1) 
                // 方案*2
                res *= (LL)2;
        }
        if (x == INT_MAX) printf("%lld\n", res / 2);
        else printf("%lld\n", res);
    }
    return 0;
}
