/**
我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello

2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello

3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

* 实现该程序
*/

/**
 * 思路: 
 * 
 * 两种匹配情况: 
 *  1. aaa型: 删除一个a, 
 *  2. aabb型: 删除一个b; 
 *      aabbcc型可以并入此种情况, 即如果是aabbcc, 删除一个b即可
 * 
 */

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        //规则1
        for(int i = 2; i < s.length(); i++) {
            // 满足aaa型
            if(s[i] == s[i-1] && s[i-1] == s[i-2]) {
                s.erase(i,1); // 删除从index开始的num个元素
                cout << s << endl;
                i--; // 删除之后下标随之移动, 此时i位于第二个a
                if(s.length() < 3)
                    break;
            }
        }
        //规则2
        for(int i = 3; i < s.length(); i++) {
            // 满足aabb型
            if(s[i] == s[i-1] && s[i-2] == s[i-3]) {
                s.erase(i, 1);
                i--; // // 删除之后下标随之移动, 此时i位于第一个b
                if(s.length() < 4)
                    break;
            }
        }
        cout << s << endl;
    }
}
