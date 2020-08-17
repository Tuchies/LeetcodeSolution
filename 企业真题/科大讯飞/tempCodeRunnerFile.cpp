#include<iostream>
#include<string>
using namespace std;

int main() {
    string s; 
    cin >> s;
    char c = s[0];
    int cnt = 1;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == c) cnt ++;
        else {
            cout << cnt << c;
            c = s[i];
            cnt = 1;
        }
    }
    cout << cnt << c << endl;
    return 0;
}