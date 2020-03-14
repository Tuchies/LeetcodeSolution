// 使用sstream获取不含空格的子串，放入数组
// 遍历数组，逆序取出

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

string reverWords(string s) {
    stringstream stream(s);
    vector<string> list;
    string str, result = "";
    while (stream >> str) {
        list.push_back(str);
    }
    for (int i = list.size() - 1; i >= 0; i --) {
        result += list[i] + " ";
    }
    return (result.size()) ? result.substr(0, result.size() - 1) : "";
}

int main() {
    string s;
    getline(cin, s);
    cout << reverWords(s);
}