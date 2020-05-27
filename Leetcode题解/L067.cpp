/**
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 输入为 非空 字符串且只包含数字 1 和 0。
 */

/**
 * 解题思路: https://leetcode-cn.com/problems/add-binary/solution/hua-jie-suan-fa-67-er-jin-zhi-qiu-he-by-guanpengch/
 * 
 * 关键在于对进位的处理, sum%2作为当前结果值, sum/2作为进位值
 * 
 * 另一个关键在于对不同长字符串的补齐问题, 遍历两字符串
 *  当前位置没有字符的(短的, 索引i<0), sum置为0
 *  当前位置有字符的(所以i>=0), 获取原字符的值(1或0), 放在sum中加减
 */ 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string addBinary(string a, string b) {
    string ans = "";
    int carry = 0;
    for(int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
        int sum = carry;
        // 获取字符串对应的某一位的值 当i<0 sum+=0（向前补0） 否则取原值char类型 刚好相差为1
        sum += i >= 0 ? a[i] - '0' : 0;
        sum += j >= 0 ? b[j] - '0' : 0;
        // 如果二者都为1  那么sum%2应该刚好为0 否则为1
        ans += sum % 2 + '0';
        // 如果二者都为1  那么ca 应该刚好为1 否则为0
        carry = sum / 2;
    }
    // 判断最后一次计算是否有进位 有则在最前面加上1 否则原样输出
    if (carry == 1)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b) << endl;
    return 0;
}