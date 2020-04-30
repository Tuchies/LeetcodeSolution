/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

/*
思路: 
回溯: 
    借助辅助栈, 压入入栈元素; 假设该压入的元素此时出栈, 判断和出栈表是否相同; 
    若相同, 则的确此时出栈; 否则继续压入下一元素

示例: 入栈 12345, 出栈45321
    压入1, 此时出栈, 出栈表首元素应该为1;  显然不是
    压入2, 此时出栈, ---------------------显然不是
    压入3, -------------------------------显然不是
    压入4, 此时出栈, 符合首元素, 分情况:
        此时对3出栈, ----------显然不是
        压入5, 符合第二个元素, 没有可压入的元素, 统统出栈, 符合
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if (popV.size() < 1 || pushV.size() < 1 || popV.size() != pushV.size()) 
        return false;
    stack<int> s;
    // 出栈数组的索引
    int index = 0;
    for(int i = 0; i < pushV.size(); i++) {
        s.push(pushV[i]);
        // 栈不为空, 且栈顶元素 = 出栈数组对应元素
        while(!s.empty() && s.top() == popV[index]) {
            // 就出栈
            s.pop();
            index ++;
        }
    }
    // 按照数组元素出完了, 就符合
    return s.empty();
}

int main() {
    int n;
    cin >> n;
    vector<int> list1(n), list2(n);
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> list2[i];
    }
    cout << IsPopOrder(list1, list2) << endl;
    return 0;
}