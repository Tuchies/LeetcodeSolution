/*
 给定N和K，求互不相同的正整数x,y,z使得x+y+z=N，且gcd(x,y)=gcd(x,z)=gcd(y,z)=K。 GCD是最大公约数

 如果有, 输出仨数, 没有输出-1(输出其中的一组可能即可)
 
 条件：1 ≤N, K≤ 1e18
*/

/**
 * 思路: 参考: https://www.nowcoder.com/discuss/455801
 * 
 * 等式两边除K，得到x'+y'+z'=N'=N/K，且x',y',z'两两互素(因为最大公约数, 所以互素)。因为是最大公约数, 所以n/k一定能整除
 * 
 * 当N'为偶数，直接构造x'=1, y'=N'/2, z' = y'-1满足条件。
 * 
 * 当N'为奇数，另x'=1,则y'+z'=N'-1。由于N'-1为偶数且y'和z'互素，必然有y',z'都为奇数。令y'=3,5,..., N' / 2逐个搜索即可。
 */

#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main () {
    int T;
    cin >> T; // t组测试数据
    ll n, k;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> k;
        // n不能整除k, 拆分的也不能
        if (n % k != 0) cout << -1 << endl;
        else {
            n /= k;
            if (n < 6) cout << -1 << endl;
            else if (n % 2 == 0) {
                ll j = (n - 1) / 2;
                cout << k << " " << k * j << " " << k * (j + 1) << endl;
            }
            else {
                bool found = false;
                for (ll p = 3; p < n - 1 - p && !found; p += 2) {
                    ll q = n - 1 - p;
                    if (__gcd(p, q) == 1) {
                        cout << k << " " << k * p << " " << k * q << endl;
                        found = true;
                    }
                }
                if (!found) cout << -1 << endl;
            }
        }
    }
}
