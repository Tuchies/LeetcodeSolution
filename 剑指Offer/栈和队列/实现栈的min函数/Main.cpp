/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
*/

/*
思路: 
用队列实现栈, 每次向队列中插入元素都更新min值

用队列实现栈: 
    本质在于使得队列右端对应栈顶, 左端对应栈顶; 那么每次向队列中插入元素时, 都把右端的元素平移到左边
*/

#include<iostream>
#include<queue>
using namespace std;

class MyStack{
private:
    queue<int> q;
    int minValue;
public:
    MyStack(){}

    // 插入元素, 平移, 更新最小值
    void push(int value) {
        if (q.empty()) {
            q.push(value);
            minValue = value;
        } 
        // 平移
        else {
            int len = q.size(), temp;
            q.push(value);
            for (int i = 0; i < len; i ++) {
                temp = q.front();
                q.pop();
                q.push(temp);
                if (temp < minValue)
                    minValue = temp;
            }
        }
    }
    void pop() {
        if(q.empty())
            return ;
        q.pop();
    }
    int top() {
        if(q.empty())
            return (int)NULL;
        return q.front();
    }
    int min() {
        if(q.empty())
            return (int)NULL;
        return minValue;
    }
};

int main() {

}