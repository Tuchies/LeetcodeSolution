
// 根据九宫格布局输出电话号码的可能组合
/**
 * 解题思路: 参见: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/tong-su-yi-dong-dong-hua-yan-shi-17-dian-hua-hao-m/
 * 
 * 回溯返回条件: index = digits.size(), 即digits全部被扫描
 * 循环的过程中: 
 * 
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> ans; // 结果数组, 设为全局变量
vector<string> numberList={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //字符表，错位使号码和索引对应
    
vector<string> letterCombinations(string digits) {
    if(digits.size()==0) return {};  // 特判
    helper(digits, {}, 0);
    return ans;
}

void helper(string digits, string s, int idx){
    if(idx == digits.size()){ // 回溯条件，保证digits全部被扫描
        ans.push_back(s);   // 将一种结果压入ans
        return;
    }
    else{
        // 依据digits的位数进行迭代，例如digits="234"
        // 第一层迭代为"2"，将遍历对应的字符串"abc"并更新字符串，依次为"a","b","c"
        // 第二层迭代为"3"，将遍历对应的字符串"def"并更新字符串，若上一层迭代为"a"，则添加、更新为"ad", "ae"与"af".
        int pos = digits[idx]-'0';  // 获取idx在digits的字符,如“2”对应的2
        string tmpStr = numberList[pos];  // 获取下标pos对应的字符串，如2对应的"abc"
        for(int i = 0;i < tmpStr.size(); i++){
            helper(digits, s+tmpStr[i], idx+1);   // 进行下一层迭代，注意同一层迭代时不改变s和idx等参数值
        }
    }
}

int main() {
    string ins;
    cin >> ins;
    vector<
    return 0;
}