/*
链接：https://www.nowcoder.com/questionTerminal/2e2510b2e41e4d3b922416e51afc077b
来源：牛客网

给出两个字符串，分别是模式串P和目标串T，判断模式串和目标串是否匹配，匹配输出 1，不匹配输出 0。模式串中‘？’可以匹配目标串中的任何字符，模式串中的 ’*’可以匹配目标串中的任何长度的串，模式串的其它字符必须和目标串的字符匹配。例如P=a?b，T=acb，则P 和 T 匹配。


输入描述:
输入第一行包含一个字符串p， (1 ≤ |p| ≤ 20).

输入第二行包含一个字符串t， (1 ≤ |t| ≤ 20).


输出描述:
输出仅包含0和1的整数，0表示p和t不匹配，1表示p和t匹配。

示例1
输入
a?b
ab
输出
0
示例2
输入
a*b
ab
输出
1
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string part, ins;
    cin >> part >> ins;

    int m = ins.size(), n = part.size();
    // dp[i][j]表示输入串前i个字符和对应的模板串前j个字符是否匹配
    vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
    dp[0][0] = true;
    // 遍历模板串, 如果模板中都是*, 则可以直接匹配
    for(int y = 1; y <= n; y++) 
        dp[0][y] = dp[0][y - 1] && part[y-1] == '*';
    // 遍历输入串, 和模板串
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            // 如果当前位置的元素相等, 或者模板是?(效果和相等一样), 就置为true
            if(ins[i-1] == part[j-1] || part[j-1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            // 如果模板当前位置的元素是*, 可以匹配任意长度的字符
            if(part[j-1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    // 下标从1开始计算, 所以此处为mn
    cout << dp[m][n] ? 1 : 0;
    return 0;
}