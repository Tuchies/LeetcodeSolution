// 前序遍历: 迭代解法, 借助栈, 目的是延迟访问


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> preorderTraversal(TreeNode* root) {
   vector<int> list;
   stack<TreeNode*> s;
   if (root != NULL) {
       s.push(root);
       TreeNode* cur = root;
        
        while (!s.empty()) {
            // 根节点出栈
            cur = s.top();
            s.pop();
            list.push_back(cur->val);
            // 右子树入栈
            if (cur->right != NULL) 
                s.push(cur->right);
            // 左子树入栈
            if (cur->left != NULL) 
                s.push(cur->left);
        }
   }
   return list;
}

 
