#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printfRes(vector<int>& list, int n) {
    if (n <= 1) cout << 0 << endl;
    // 排序
    sort(list.begin(),list.end());
    int sums = 0;
    int idx = 0;
    // 遍历
    for (int i = n-1;i >= 0;i --) {
        if (i%2 ==0) sums += list[i];
        else sums -= list[i];
        if (sums == 0) {
            idx = i;
            break;
        }
    }
    // 计算价值
    int res = 0;
    if (idx <= 0) cout << 0 << endl;
    else {
        for (int j = idx-1; j >= 0;j --) {
            res += list[j];
        }
        cout << res << endl;
    }
}

int main() {
    int t, n, tmp;
    scanf("%d",&t);
    for (int i = 0;i < t; i ++) {
        scanf("%d",&n);
        vector<int> list(n);
        for (int j = 0; j < n; j++) {
            scanf("%d",&list[j]);
        }
        printfRes(list, n); 
    }
    return 0;
}