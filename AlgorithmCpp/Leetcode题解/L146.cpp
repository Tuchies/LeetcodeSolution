/**
 * 实现LRU缓存机制
 * put: 如果key值已经存在, 更新其value值; 否则插入该组数据; 当达到缓存容量的最大限制时, 去除最近使用最少的那组数据, 预留出弓箭
 * get: 通过key获取value值
 * 
 * 要求在线性时间内完成
 */

/**
 * 无序map + 双向链表实现
 * 
 * 因为要求在O(1)时间内实现, 所以通过get返回值时不能遍历, 需要使用map
 * 其次, 保证最近使用的 key-value数对一直在链表头部
 *  当新插入一组数据, 且缓冲区满时, 直接替换掉尾部的数对即可
 * 
 * 关键在于: 实现remove()和setHead()方法
 */
#include<iostream>
#include<map>

using namespace std;

class LRUCache {

// 带有键值对的双向链表
struct Node
{
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int key, int value) : key(key), value(value), pre(NULL), next(NULL){}
};

private:
    int size; // 缓冲区大小
    Node* head; // 头节点
    Node* tail; // 尾节点
    map<int, Node*> p;

public:
    // 初始化并指定容量
    LRUCache(int capacity) {
        this->size = capacity;
        head = NULL;
        tail = NULL;
    }

    /**
     * 如果key不存在, 返回-1
     * 如果key存在, 则这组数值是最近访问的, 应该调换到链表头部, 再返回值
     *  1. 删除链表中的节点
     *  2. 插入到链表头部
     *  3. 返回值
     */ 
    int get(int key) {
        // 当该 key 值存在
        if(p.count(key) > 0) {
            // 获取该key对应的value
            Node* cur = p[key];
            int value = cur->value;
            // 删除双向链表中的节点
            remove(cur);                
            // 将节点重现插入到缓冲区的头部
            setHead(cur);                     
            return value;
        }
        return -1;
    }

    /**
     * 如果key存在
     *  1. 删除原来的节点
     *  2. 将新值节点插入到链表的头部
     */ 
    void put(int key, int value) {
        // 1.当该 key 值存在
        if(p.count(key) > 0) {
            // 删除该 key 对应的原来节点
            Node* cur = p[key];
            cur->value = value;
            remove(cur);                        
            // 将节点重现插入到缓冲区的头部
            setHead(cur);
        }
        // 2. 当该key值不存在
        else {
            Node* node = new Node(key, value);
            // 判断当前缓冲区大小已经满了
            if(p.size() >= size) {
                // 定位到尾部节点, 并删除
                map<int, Node*>::iterator it = p.find(tail->key);
                remove(tail);
                p.erase(it);// 这里erase 函数参数是迭代器类型，所以上面需要使用迭代器类型
                // 将新节点插入到缓冲区的头部
            }
            //else 此时因为动作和上面重复，所以直接合并使用
            //还没有满：将新节点插入到缓冲区的头部
            {
                setHead(node);
                p[key] = node;
            }
        }
    }

    // 删除当前节点
    void remove(Node* cur) {
        // 当前节点是 head
        if(cur == head)
            head = cur->next;
        // 当前节点是 tail
        else if(cur == tail)
            tail = cur->pre;
        else {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
        }
    }

    // 将当前节点插入到头部
    void setHead(Node* cur) {
        cur->next = head;
        if(head != nullptr)
            head->pre = cur;
        head = cur;//重现更新head

        if(tail==nullptr)
            tail = head;
    }
};

int main() {
    LRUCache *lru = new LRUCache(4);
    lru->put(0, 0);
    lru->put(1, 1);
    lru->put(2, 2);
    lru->put(3, 3);
    lru->get(0);
    lru->put(4, 4);
    cout << lru->get(0) << endl;
    delete lru;
    return 0;
}