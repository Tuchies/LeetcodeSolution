/**
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 */

/**
 * 解题思路: 
 * 关键在于忽略标点和大小写, 只考虑字符和数字
 * DP不太适合, 考虑使用双指针
 * 
 * 分别从前往后, 从后往前遍历, 遇到标点就跳过去(移动指针), 否则进行比较
 *  相等则继续
 */

#include<iostream>
#include<string>
using namespace std;

bool isNumOrChar(char c) {
    if (tolower(c) >= 'a' && tolower(c) <= 'z' || c >= '0' && c <= '9') 
        return true;
    else return false;
}

bool isPalindrome(string s) {
    if (s.size() < 1 || s == " ") 
        return true;
    // 初始化指针
    int start = 0, end = s.size() - 1;
    // 遍历
    while(start < end) {
        // 遇到标点, 跳过去
        if (! isNumOrChar(s[start])) start ++;
        if (! isNumOrChar(s[end])) end --;

        // 数字 / 字母则比较
        if (isNumOrChar(s[start]) && isNumOrChar(s[end])) {
            if (tolower(s[start]) == tolower(s[end])) {
                start ++; end --;
            }
            else return false;
        }
    }
    return true;
}

int main() {
    string ss;
    cin >> ss;
    cout << isPalindrome(ss);
    return 0;
}

