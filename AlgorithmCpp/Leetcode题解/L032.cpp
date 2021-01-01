// 最长有效括号字串, "20题: 有效括号问题"的变式, 因为括号的对称性和排列的有序性, 天然适合用栈结构辅助解答

/*
对于遇到的每个 左括号，我们将它的下标放入栈中。
对于遇到的每个 右括号 ，我们弹出栈顶的元素并将当前元素的下标与弹出元素下标作差，得出当前有效括号字符串的长度。

通过这种方法，继续计算有效子字符串的长度，并最终返回最长有效子字符串的长度。
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int longestValidParentheses(string s) {
    
}

int main() {
    string ins;
    cin >> ins;
    cout << longestValidParentheses(ins);
    return 0;
}