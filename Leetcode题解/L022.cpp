// TODO 该问题待解决

// 生成N对可能的括号组合：原则，左右括号数量相等，且均等于N；左括号必须在对应的右括号前

#include<iostream>
#include<vector>

using namespace std;

void helper(vector<string>list, string current, int left, int right, int n){
    if(current.size() == n*2){ // 符合终止条件
        list.push_back(current);
        return; 
    }
    if(left < n) { //左括号数量不够
        helper(list, current+"(", left+1, right, n);
    }
    if(right < left) { //右括号不等于左括号，且保证右括号在左前
        helper(list, current+")", left, right+1, n);
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> list;
    helper(list,"", 0, 0, n);
    return list;
}

int main() {
    int in;
    cin >> in;
    vector<string> s = generateParenthesis(in);
    for(int i = 0; i < s.size(); i ++) {
        cout << s.size() << endl;
        cout << s[i] << endl;
    }
    return 0;
}