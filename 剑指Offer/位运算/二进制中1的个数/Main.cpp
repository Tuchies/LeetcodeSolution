// 给定一个整数, 输出其二进制中1的个数, 其中负数用补码表示


#include<iostream>
#include<bitset>

using namespace std;



int NumberOf1(int n) {
    /*
    直接: 
    return bitset<32>(n).count();
    */
    // 或者
    bitset<32>s (n);
    int count = 0;
    for(int i = 0; i < s.size(); i ++) {
        if (s[i] == 1)
            count ++;
    }
    return count;
}
int main() {
    int num;
    cin >> num;
    cout << NumberOf1(num);
    return 0;
}