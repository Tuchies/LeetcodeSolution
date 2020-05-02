/*
由上往下打印二叉树
*/

/*
思路:
层次遍历二叉树, 把节点装进list中
*/

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> list;
    if (root == NULL) {
        return list;
    }
    if (root->left == NULL && root->right == NULL) {
        list.push_back(root->val);
        return list;
    }
    // 开始层次遍历
    queue<TreeNode*> q;
    q.push(root);
    while(! q.empty()) {
        int size = q.size();
        while(size --) {
            TreeNode* temp = q.front();
            list.push_back(temp->val);
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            } 
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return list;
}

// 从BFS构建二叉树
TreeNode* createTree(vector<int> nodes, int currentIndex) {
    if (currentIndex > nodes.size() - 1)
        return (TreeNode*)NULL;
    TreeNode* node = new TreeNode(nodes[currentIndex]);
    // 构建左子树, 下标为 2i + 1
    node->left = createTree(nodes, 2 * currentIndex + 1);
    // 构建右子树
    node->right = createTree(nodes, 2 * currentIndex + 2);
    return node;
}

int main() {
    int n;
    vector<int> list;
    while(cin >> n) {
        list.push_back(n);
    }   
    TreeNode* root = createTree(list, 0);
    vector<int> ans = PrintFromTopToBottom(root);
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}