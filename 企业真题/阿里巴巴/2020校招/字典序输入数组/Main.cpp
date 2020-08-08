/*
给一个n<=10，按字典序输出1...n，相邻数字绝对值不为1，的排列。
输入：
4
输出：
2 4 1 3
3 1 4 2
*/

/**
 * 回溯
 * 剪枝条件: 相差超过1
 * 返回条件: trace.size == nums.size
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printTrace(vector<int>& list) {
    for (int j = 0; j < list.size(); j ++)
        cout << list[j] << " ";
}

bool has(vector<int>&list, int i ) {
    for (int j = 0; j < list.size(); j ++) {
        if (list[j] == i) return true;
    }
    cout << endl;
    return false;
}

void backtrace(vector<int>& trace, int n) {
    if (trace.size() == n) {
        printTrace(trace);
        return;
    }
        
    // 遍历
    for (int i = 1; i < n+1; i ++) {
        // 剪枝
        if (has(trace, i)) continue;
        trace.push_back(i);
        backtrace(trace,n);
        trace.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> track;
    backtrace(track, n);
    return 0;
}