/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> res;

void helper(string track, int left, int right, int n){
    // 要生成n对括号, 长度就是n*2
    if(track.size() == n*2) { 
        res.push_back(track);
    }
    else {
        if(left < n) { // 左括号数量不够
            helper(track+"(", left+1, right, n);
        }
        // 右括号不等于左括号，且保证右括号在左前
        if(right < left) { 
            helper(track+")", left, right+1, n);
        }
    }
}

vector<string> generateParenthesis(int n) {
    helper("", 0, 0, n);
    return res;
}

int main() {
    int in;
    cin >> in;
    vector<string> s = generateParenthesis(in);
    for(int i = 0; i < s.size(); i ++) {
        cout << s[i] << endl;
    }
    return 0;
}