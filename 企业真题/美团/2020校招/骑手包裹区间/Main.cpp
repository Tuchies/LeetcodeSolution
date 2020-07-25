/**

2110年美团外卖火星第3000号配送站点有26名骑手，分别以大写字母A-Z命名，因此可以称呼这些骑手为黄家骑士特工A，黄家骑士特工B…黄家骑士特工Z，某美团黑珍珠餐厅的外卖流水线上会顺序产出一组包裹，美团配送调度引擎已经将包裹分配到骑手，并在包裹上粘贴好骑手名称，如RETTEBTAE代表一组流水线包裹共9个，同时分配给了名字为A B E R T的5名骑手。请在不打乱流水线产出顺序的情况下，把这组包裹划分为尽可能多的片段，同一个骑手只会出现在其中的一个片段，返回一个表示每个包裹片段的长度的列表。

输入描述:
输入数据只有一行，为一个字符串(不包含引号)，长度不超过1000，只包含大写字母'A'到'Z'，字符之间无空格。

输出描述:
输出每个分割成片段的包裹组的长度，每个长度之间通过空格隔开

示例1
输入
MPMPCPMCMDEFEGDEHINHKLIN
输出
9 7 8
说明
划分结果为MPMPCPMCM,DEFEGDE,HINHKLIN。

每个骑手最多出现在一个片段中。

像MPMPCPMCMDEFEGDE,HINHKLIN的划分是错误的，因为划分的片段数较少。
*/

/**
 * 题目翻译: 将一组字母序列分段, 使得同一个字母只会出现在一个片段中
 * 
 * 思路: 滑动窗口
 *  判断当前字符的最后一个位置, 使一个指针j指向最后一个位置, 然后指针i从当前字符下一个字符开始遍历双指针的中间字符;
 *  对于每一个中间字符, 找该字符的最后一次位置, 如果超过了指针j下标, 就更新指针j
 *  目的是保证指针j和指针i之间的字符, 在后续中不会再出现
 * 
 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int getLastIndex(string s, char c) {
    for (int x = s.size()-1; x >= 0; x --) {
        if (s[x] == c) 
            return x;
    }
    return -1;
}

int main() {
    string ins;
    cin >> ins;
    if (ins.size() < 1) cout << 0 << endl;

    int i=0, curIndex=0, len=ins.size();
    // j表示当前字符下标
    while(curIndex < len) {
        char cur = ins[curIndex];
        // 当前字符的最后一次位置
        int tail = getLastIndex(ins, cur);
        int pre = curIndex;
        i = curIndex+1;
        curIndex = tail;
        // 从当前字符下一个字符开始, 如果它在当前字符最后一次位置前遍
        // 就遍历所有的中间节点
        while(i < curIndex){
            char inner = ins[i];
            // 和每个中间节点的最后一次位置比较
            // 目的是找出可以连续的最长片段
            curIndex = max(curIndex, getLastIndex(ins,inner));
            i ++;
        }
        // cur_index始终保持了连续片段的最后一个字符下标
        curIndex ++;
        // 注意要减去初始字符下标
        cout << curIndex-pre << " ";
    }
    return 0;
}