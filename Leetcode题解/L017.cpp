
// 根据九宫格布局输出电话号码的可能组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

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

vector<string> ans; 
vector<string> numberList={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //字符表，错位使号码和索引对应

void helper(string digits, string s, int idx);
    
vector<string> letterCombinations(string digits) {
    if(digits.size()==0) 
        return {};  
    helper(digits, {}, 0);
    return ans;
}

// idx标记回溯条件, s存放可能产生的结果string
void helper(string digits, string s, int idx){
    // 回溯条件, idx标记保证digits输入被扫描完全
    if(idx == digits.size()){ 
        ans.push_back(s);   
        return;
    }
    else{
        // 依据digits的位数进行迭代，例如digits="234"
        // 第一层迭代为"2"，将遍历对应的字符串"abc"并更新字符串，依次为"a","b","c"
        // 第二层迭代为"3"，将遍历对应的字符串"def"并更新字符串，若上一层迭代为"a"，则添加、更新为"ad", "ae"与"af".
        int pos = digits[idx]-'0';  
        // 根据字符数字, 获取对应的可能字符, 如2对应的"abc"
        string tmpStr = numberList[pos];  
        // 根据字符串"abc", 遍历所有可能的字符, 然后回溯
        for(int i = 0; i < tmpStr.size(); i++){
            helper(digits, s+tmpStr[i], idx+1);   
        }
    }
}

int main() {
    string ins;
    cin >> ins;
    vector<string> ans = letterCombinations(ins);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}