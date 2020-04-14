// 用栈实现队列：pop/empty/peek/push

// 实现：定义两个栈，一个入栈inStack，一个出栈outStack；只有当out栈中为空的时候，才可将in栈中的元素倒入out中（一次倒完）

#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;
    //1.只有当out栈中为空的时候，才可以将in栈中的元素倒入out栈
    //2.而且in栈要一次倒完
    void in2out(){
        if(outStack.empty()){
            while(! inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        //直接压入
        inStack.push(x);
    }
    
    int pop() {
        //如果outStack中没有元素，就先把inStack中的元素依次弹出压入outStack
        in2out();
        //如果outStack中已经有元素了,就直接获取outStack的栈顶元素
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    int peek() {
        //如果outStack中没有元素，就先把inStack中的元素依次弹出压入outStack
        in2out();
        //outStack中已经有元素了,就直接获取outStack的栈顶元素
        int res = outStack.top();
        return res;
    }
    
    bool empty() {
        //只要有一个栈元素不为空，队列就不为空
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    cout << q->pop() << endl;
    cout << q->peek() << endl;
    cout << q->empty() << endl;
    return 0;
    delete q;
}