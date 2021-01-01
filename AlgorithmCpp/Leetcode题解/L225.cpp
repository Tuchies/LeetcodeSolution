// 用队列实现栈：实现pop/push/top/enpty四个方法

// 单队列实现：就需要将队列右端对应栈头（先访问到），将队列左端对应栈尾部（后访问到）；这就需要，每次从队列左端添加进一个元素，把其右端的所有元素都平移出来，放回对列左端

// 注意：在C++中，queue.pop()只是移除队列右端元素，不返回值

#include<iostream>
#include<queue>

using namespace std;

class MyStack{
public:
    MyStack() {}

    // 每次将元素压入栈，都要移动队列中现有的元素
    void push(int x) {
        q.push(x);
        for(int i = 1; i < q.size(); i ++) {
            // 在左端压入最右端的
            q.push(q.front());
            // 移除最右端的
            q.pop();
        }
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    // 弹出栈顶元素，返回其值
    int pop() {
        int result = top();
        q.pop();
        return result;
    }

private:
    queue<int> q;
};

int main() {
    MyStack *s = new MyStack();
    s->push(2);
    cout << s->top() << endl;
    cout << s->empty();
    cout << s->pop();
    return 0;
    delete s;
}