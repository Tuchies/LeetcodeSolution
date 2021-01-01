// 判断回文字符串，即从中心元素开始，两侧的元素相同；由此不断向两侧延申，直到遇到两端不同的元素，就找到了最长回文串
// 基于上述思路，显然可以看出从子问题（中心元素）可以推导出目标问题（最长回文串）的解，且子问题的解会被多次调用

// 举例：对于字符串umizimu,izi是回文串 -> mizim是回文串 -> umizimu是回文串；可以看到，中间部分会被重复调用
// 推导方程：设F(i,j)表示字符串i~j是否为回文字符串，为True的条件是：F(i+1,j-1)为True && i==j

// 本题难点：在于找到判断回文字符串的思路，即从中间元素开始，再向着两侧延申，如果中间小部分是回文串，且两侧元素相同，则整个是回文串；基于该思路，很容易可以判断出要用动态规划求解

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestPalindrome(string s) {
    int len = s.length();
    string result; //保存结果

    // 最小部分的处理
    if (len < 2) {
        return s;
    }
    
    //定义二维数组，存放字符串S(i~j)的判断结果
    vector< vector<bool> > dp(len, vector<bool>(len));

    for(int i = 0 ;i < len; i++) {
        for(int j = 0; j <= i ;j ++){ //双指针遍历字符串

            //字符串i~j为真的条件：两端字符相同且中间部分为回文串
            //如果两端字符相同，且中间只有一个字符，也为回文串
            if(s[i] == s[j] && ( i - j < 2 || dp[j+1][i-1])) {
                dp[j][i] = true;
            }
            //找到回文串，且该回文串长度大于 之前的最长回文串，就标记该串为最长
            if (dp[j][i] && (i - j + 1 > result.length())) {
                result = s.substr(j,i - j + 1);//注意C艹的substr方法与Java不同，为从i开始的n个字符
            }
        }
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;
}
