/*
小易在维护数据的时候遇到一个需求，具体来说小易有一系列数据，这些数据了构成一个长度为n的数字序列，接下来小易会在这个序列上进行q次操作。
每次操作有一个查询的数字x，小易需要将序列数据中所有大于等于x的数字都减一，并输出在本次操作中有多少个数字被减一了。
小易犯了难，希望你能帮帮他。

输入描述:
第一行n,q，表示数字个数和操作个数。 
接下来一行n个数表示初始的数字。 
接下来q行，每行一个数，表示指定的数字x。

输出描述:
对于每个询问，输出一个数字表示答案
示例1
输入
4 3
1 2 3 4
4
3
1
输出
1
2
4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subList(vector<int> &ans, int start) {
    for (;start < ans.size(); start ++) {
        ans[start] -= 1;
    }
}

int main() {
    int n,q,x;
    cin >> n >> q;
    vector<int> list(n);
    // 构建序列
    for(int i = 0; i < n; i ++) {
        cin >> list[i];
    }
    // 排序
    sort(list.begin(),list.end());
    // 获取操作数字x
    while (q --) {
        cin >> x;
        // 找出序列中大于等于x的数字的个数
        // 如果开头数字就大于等于x
        if (list[0] >= x) {
            cout << list.size() << endl;
            // 把所有数字都减一
            subList(list,0);
        }
        // 如果末尾数字还小于x
        else if (list[list.size()-1] < x)
            cout << 0 << endl;
        else {
            for (int j = 0; j < list.size()-1; j ++) {
                if (list[j] < x && list[j+1] >= x) {
                    cout << list.size() - j - 1 << endl;
                    subList(list,j+1);
                }
            }
        }
    }
    return 0;
}