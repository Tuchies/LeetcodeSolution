// 中序遍历的递归解法：需要经每次访问的节点都放置在数组中，因此需要构建辅助函数

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<int> list;

vector<int> inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        list.push_back(root->val);
        inorderTraversal(root->right);
    }
    return list;
}   

int main() {
    TreeNode *t;
    t->val = 9; 
    TreeNode *l;
    l->val = 8;
    TreeNode *r;
    r->val = 0;
    t->left = l;
    t->right = r;
    vector<int> cc = inorderTraversal(t);
    for(int i= 0; i < cc.size(); i ++) {
        cout << cc[i]<< endl;
    }
    return 0;
    delete t;
    delete l;
    delete r; 
}

