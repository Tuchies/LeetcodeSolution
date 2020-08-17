#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void sortString(vector<char>& list, int len) {
    // 特判
    if (len <= 0) return;
    // 冒泡排序
    for (int i = 0; i < len; i ++) {
        for (int j = i+1; j < len; j ++) {
            // 比较, 如果小写不相等, 执行正常逻辑
            if (tolower(list[i]) != tolower(list[j])) {
                if (list[i] > list[j]) {
                    // 执行交换
                    char tmp1 = list[i];
                    list[i] = list[j];
                    list[j] = tmp1;
                }
            }
            // 如果小写相等, 小写(大)放在大写前边
            else {
                if (list[i] < list[j]) {
                    // 执行交换
                    char tmp = list[i];
                    list[i] = list[j];
                    list[j] = tmp;
                }
            }
        }
    }
}

int main() {
    vector<char> list(5);
    list.push_back('S');
    list.push_back('y');
    list.push_back('s');
    list.push_back('t');
    list.push_back('e');
    sortString(list, list.size());
    // 打印结果
    for (int i = 0; i < list.size();  i ++) {
        cout << list[i] << endl;
    }
    return 0;
}


/*
实现对一组无序的字母进行从小到大排序（区分大小写），当两个字母相同时，小写字母放在大写字母前。
示例:
 {'S','y','s','t','e','m','C','a','l','l','e','r'}
输出:
aCeellmrsSty
*/