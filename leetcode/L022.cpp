#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> generateParenthesis(int n) {
    
}

int main() {
    int n ;
    cin >> n;
    vector<string> list = generateParenthesis(n);
    for ( int i = 0; i < list.size(); i ++) {
        cout << list[i] << endl;
    }
}