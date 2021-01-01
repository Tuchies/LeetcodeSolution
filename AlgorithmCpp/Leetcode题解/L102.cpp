// 二叉树的层次遍历：广度优先算法

// 返回的二维数组，第一维表示层次索引，第二维对应该层次中的元素

// 递归解法：递归解法的本质还是深度遍历DFS，从根节点开始递归，遍历左子树、右子树，子树到头了就返回，只不过是在DFS的基础上添加了层次索引level，拥有构建数组

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > result;

void addVector(TreeNode *root, int level) {
    // 某部分子树遍历到头，就返回
    if(root == NULL)    return;

    if(result.size() == level)       
        result.resize(level + 1);    
    result[level].push_back(root->val);
    // 遍历根节点的左子树
    addVector(root->left, level+1);
    // 遍历跟阶段的右子树
    addVector(root->right, level+1);
}

vector<vector<int> > levelOrder(TreeNode* root) {
    addVector(root, 0);
    return result;
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
    vector<vector<int> > cc = levelOrder(t);
    for(int i= 0; i < cc.size(); i ++) {
        for(int j = 0; j < cc[i].size(); j ++) {
            cout << cc[i][j] << endl;
        }
    }
    return 0;
    delete t;
    delete l;
    delete r; 
}