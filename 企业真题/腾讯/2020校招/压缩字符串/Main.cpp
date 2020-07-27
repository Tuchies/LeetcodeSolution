/*

小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？ 

输入描述:
输入第一行包含一个字符串s，代表压缩后的字符串。
S的长度<=1000;
S仅包含大写字母、[、]、|;
解压后的字符串长度不超过100000;
压缩递归层数不超过10层;


输出描述:
输出一个字符串，代表解压后的字符串。
示例1
输入
HG[3|B[2|CA]]F
输出
HGBCACABCACABCACAF
说明
HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
*/

#include<iostream>
#include<string>
using namespace std;

string getZip(string s) {
    if (s.size() < 5) return s;
    
    // end指针从0开始, 所以首先找到的]必然是最内层的
    int end = 0;
    while(end < s.length()){
        if(s[end] == ']'){
            int start = end; // start用来向前寻找与]相匹配的[
            int k = 0; // k用来记录'|'所在位置
            // 在找[的过程中, 顺便找到|
            while(s[start] != '['){
                if(s[start] == '|')
                    k = start;
                start --;
            }
            // 指针start和指针k之间的就是数字
            int len = stoi(s.substr(start+1,k-start));
            // 指针k和指针end之间的就要重复的
            string s1 = s.substr(k+1, end - k - 1);
            string s2;
            // 执行重复
            for(int si = 0; si < len; si++) {
                s2 += s1;
            }
            // 将指针start到指针end之间的替换为解压后的
            s = s.replace(start,end-start+1,s2);
            // 替换后end所指向的内容变化，从替换部分的头开始再寻找
            end = start;
        }
        end ++;
    }
    return s;
}

int main() {
    string ins;
    cin >> ins;
    cout << getZip(ins);
    return 0;
}