/*
返回一个无符号整数, 二进制表达中1的个数
*/

/*
该方法本地可运行正确测试用例, 网站运行出错
*/

#include<iostream>
#include<string>
#include<sstream>
typedef unsigned __int32 uint32_t;
using namespace std;

int hammingWeight(uint32_t n) {
    if (n == 0) return 0;
    int count = 0;
    string str;
    stringstream ss;
    ss << n;
    ss >> str;
    for (int i = 0;i < str.size(); i ++) {
        if (str[i] == '1')
            count ++;
    }
    return count;
}

int main() {
    uint32_t n;
    cin >>n;
    cout << hammingWeight(n);
    return 0;
}