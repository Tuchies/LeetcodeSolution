/**
 * 
以字符串的形式读入两个数字，再以字符串的形式输出两个数字的和。

输入描述:
输入两行，表示两个数字a和b，-109 <= a , b <= 109  ，用双引号括起。

输出描述:
输出a+b的值，用双引号括起。
*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    string a, b;
    long long aans, bans;
    cin >> a >> b;

    a.erase(0,1); a.erase(a.size()-1,1);
    b.erase(0,1); b.erase(b.size()-1,1);

    stringstream stream;
    stream << a;
    stream >> aans;
    stream.clear();
    stream << b;
    stream >> bans;
    cout << "\"" << aans + bans << "\"";
    return 0;
}