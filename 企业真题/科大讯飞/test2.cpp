#include<iostream>
#include<string>
using namespace std;

// 压缩字符串

int main() {
    string s; 
    cin >> s;
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < s.length(); i ++) {
        if (s[i] == c) cnt ++;
        else {
            if (cnt == 1) {
                cout << c;
            }
            else {
                cout << cnt << c;
            }
            c = s[i];
            cnt = 1;
        }
    }
    if (cnt == 1) {
        cout << c;
    }
    else {
        cout << cnt << c;
    }
    return 0;
}