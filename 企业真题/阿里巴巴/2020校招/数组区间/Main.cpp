/*
第一行两个整数n,m。m<=n<=400000。第二行是长度为n的数组a，a_i<=n。
计算a有多少个区间（子数组）满足：存在某个数字v，使得v在数组区间出现次数大于等于m。

输入：
5 2
1 2 1 2 5
输出：
5
解释：区间[1,3][1,4][1,5][2,4][2,5]，要么1出现2次以上，要么2出现超过2次以上。
*/

/*

线性扫描。计算以i结尾的满足条件的区间数cnt[i]。

根据题意有一个结论：对于以i结尾的区间，若j使得a[j...i]满足条件，则对j'<j，a[j'...i]都满足条件。所以只要找到满足条件最大的j记作pt，cnt[i]就等于pt+1了（不是pt）。

这样问题就转化成循环维护pt值。方法是，对已扫描的每个值v，记录其出现过的位置列表pos。扫描到a[i]时，查看到目前为止倒数第m-1次出现a[i]的位置pre_m（如果存在），且pre_m大于pt，则更新pt为pre_m。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n, m;
    int num;
    int pt = -1, ans = 0;
    unordered_map<int,vector<int> > hash;

    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        // 当前数组值映射的list中, 放入当前值的下标
        hash[num].push_back(i); 

        if (hash[num].size() >= m) {
            int preM = hash[num].at(hash[num].size()-m);
            pt = max(pt,preM);
        }
        ans += pt + 1;
    }   
    cout << ans;
    return 0;
}