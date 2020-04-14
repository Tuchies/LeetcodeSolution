// 广度优先遍历：BFS的迭代解法

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    
    if (root == NULL)   
        return {};  
    queue<TreeNode*> q;     
    q.push(root);  

    while (!q.empty()) {  
        //存放每一层的元素值
        vector<int>level;               
        //队列大小表示当前层数的元素个数
        int count = q.size();           

        //count--逐个对该层元素进行处理  
        while(count--) {
            TreeNode *temp = q.front();             
            q.pop();     
            level.push_back(temp->val);
            if(temp->left)     
                q.push(temp->left);
            if(temp->right)    
                q.push(temp->right);
        }
        //将当层元素的vector添加到结果列表
        result.push_back(level);          
    }
    return result;
};
