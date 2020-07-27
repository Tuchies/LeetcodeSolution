/**
 * 给定两字符串, 若调换字母顺序后相同, 则视为相等
 * 如: mary army 视为相等
 */

/**
 * 思路: 统计每个字符串中字符的粗线次数, 然后比较是否相等
 */ 

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void check(string s1, string s2) {
    if (s1.size() != s2.size()){
        printf("%s\n", "false");
        return;
    } 
    vector<int> map1(123,0);
    vector<int> map2(123,0);
    int index;
    for (int i = 0; i < s1.size(); i ++) {
        // 位图的索引
        index = (int)s1[i]; // 从字符转为ascii码, 作为位图下标
        map1[index] ++;
        index = (int)s2[i];
        map2[index] ++;
    }
    // 检验位图是否相等
    for (int j = 65; j < 123; j ++) {
        if (map1[j] != map2[j]) {
            cout << "false";
            return;
        }
    }
    cout << "true";
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    check(s1, s2);
    return 0;
}