// 从数组末位开始遍历，加一，保留个位数
// 若此时没有发生进位，则可以直接返回结果
// 若发生进位，则继续遍历，依次执行“加一，保留个位，判断进位”
//    若全部遍历仍未返回，即均为9发生进位，则新建一长度加一的数组，使首位为1，其余为0

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i --) {
        digits[i] ++; //plus one
        digits[i] = digits[i] % 10;
        if (digits[i] != 0) {
            return digits; // no carry
        }
    }
    vector<int> result(digits.size() + 1, 0);
    result[0] = 1;
    return result;
}

int main() {
    string inp;
    cin >> inp;
    vector<int> digits;
    for (int i = 0; i < inp.size(); i ++) {
        digits.push_back(inp[i] - '0');
    }
   vector<int> result = plusOne(digits);
   for (int i = 0; i< result.size(); i ++) {
       cout << result[i] << ",";
   }
}