// TODO 该题目的解法有些问题

// 根据九宫格布局输出电话号码的可能组合
// 回溯法递归求解，接收两个参数：1.当前数字已经组成的对应字符串，2.剩余的数字字符串；返回条件：剩余的字符串为空，即所有的数字都匹配完；定义一个全局list存放可能的结果，当一个分支完整地遍历之后记录结果

#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, string> the_map;
vector<string> result;

void helper(string current, string rest) {
    the_map["2"] = "abc";
    the_map["3"] = "def";
    the_map["4"] = "ghi";
    the_map["5"] = "jkl";
    the_map["6"] = "mno";
    the_map["7"] = "pqrs";
    the_map["8"] = "tuv";
    the_map["9"] = "wxyz";

    if(rest.size() == 0) {//如果该分支已遍历完成
        result.push_back(current);
        return;
    } else { //如果没有遍历完
        // 获取rest数字串的第一个数字对应的字符串
        string first = rest.substr(0, 1);
        string words = the_map[first];
        cout << words << endl;
        // 遍历该字符串的每个字符，然后递归
        for(int i = 0; i < words.size(); i ++) {
            string temp = the_map[first].substr(i, i+1);
            cout << temp << "--" << i<<endl;
            // 开始下一个数字的匹配
            // 每次都截取rest串
            helper(current+temp, rest.substr(1));
        }
    }
    
}

vector<string> letterCombinations(string digits) {
    if(digits.size() > 0) {
        helper("", digits);//当前尚未组成字符串
    }
    return result;
}

int main() {
    string in;
    cin >> in;
    vector<string> s = letterCombinations(in);
    cout<< s.size()<<endl;
    for(int i = 0; i < s.size(); i ++) {
        cout << s[i] << endl;
    }
    return 0;
}