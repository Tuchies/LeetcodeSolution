// 统计小于n的质数的个数

// 厄拉多塞筛法: 遍历到数字2, 排除2的倍数; 遍历到数字3, 排除3的倍数...

#include<iostream>
#include<vector>

using namespace std;

int countPrimes(int n) {
    vector<bool> isPrim(n, true);
    int count = 0;
     for (int i = 2; i < n; i++) {
        if (isPrim[i]) {
            count++;
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                isPrim[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >>n;
    cout << countPrimes(n);
    return 0;
}