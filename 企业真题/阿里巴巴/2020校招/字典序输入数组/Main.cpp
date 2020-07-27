/*
给一个n<=10，按字典序输出1...n，相邻数字绝对值不为1，的排列。
输入：
4
输出：
2 4 1 3
3 1 4 2
*/

#include<iostream>
#include<vector>
using namespace std;

void helper(vector<int> val, vector<int>& cur, int n) {
    if (n == 0) {
        for (int i = 0; i < cur.size(); i ++)
            cout << cur[i] << " ";
    }
    else {
        for (int j = 1; j < val.size(); j ++) {
            if (val[j] || (cur.size() && j >= cur[cur.size()-1]-1 && j <= cur[cur.size()-1]+1))
                continue;
            val[j] = 1;
            cur.push_back(j);
            helper(val,cur,n-1);
            val[j] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> val(n+1);
    vector<int> cur;
    helper(val,cur,n);
}