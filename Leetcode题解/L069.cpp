/**
 * 求整数x的平方根, 如果结果是非整数, 则只保留整数部分
 */

/**
 * 解题思路: 
 * 所求结果可以视为: 满足 pow(k,2) <= x 表达式的最大k值
 * 
 * 对k使用二分查找
 */

#include<iostream>
using namespace std;

int mySqrt(int x) {
    int start = 0, temp = x, ans = -1;
    while (start <= temp) {
        int mid = start + (temp - start) / 2;
        if (mid * mid <= x) {
            ans = mid;
            start = mid + 1;
        }
        else {
            temp = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << mySqrt(n) << endl;
    return 0;
}