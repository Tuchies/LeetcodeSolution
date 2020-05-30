/**
 * 给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

/**
 * 解题思路: 参见https://leetcode-cn.com/problems/excel-sheet-column-number/solution/hua-jie-suan-fa-171-excelbiao-lie-xu-hao-by-guanpe/
 * 
 * 将26个字母视为26进制数, A表示1, 
 * 则当前字母所表示的数 num = cur_num - 'A' + 1
 * 如: Z, 表示的数就是 26-1+1 = 26
 *  
 * 26进制中, 每26个数就向前进一位, 则 ans = ans * 26 + num
 *  类比十进制中的进位, 每进一位, ...*10+...
 * 如: ZY, 表示: 26*26 + 25 = 701; (Y表示25)
 * 
 */

#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
    if (s.size() < 1)
        return (int)NULL;
    int ans = 0;
    int temp;
    // 从高位开始遍历, 每向低位移动一位, 就 *26
    for (int i = 0; i < s.size(); i ++) {
        temp = s[i]-'A'+1;
        ans = ans*26+temp;
    }
    return ans;
}

int main() {
    string ss;
    cin >> ss;
    cout << titleToNumber(ss);
    return 0;
}