/**
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */

/**
 * 层次遍历:
 *  借助队列实现: 
 *      1. 根节点入队列
 *      2. 遍历每一层前, 记录队列size, 也即是当前层的节点个数
 *      3. 遍历每一层时, 将下一层的节点入队列, 
 *      4. 直到队列为空
 */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > vec;
    if(pRoot == NULL) return vec;

    queue<TreeNode*> q;
    q.push(pRoot);

    while(!q.empty()) {
        int lo = 0, hi = q.size();
        vector<int> c;
        while(lo++ < hi) {
            TreeNode *t = q.front();
            q.pop();
            c.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        vec.push_back(c);
    }
    return vec;
}