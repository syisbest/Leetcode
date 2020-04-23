/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)   return false;
        int value=root->val;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* newNode=que.front();
            que.pop();
            if(newNode->left)   que.push(newNode->left);
            if(newNode->right)  que.push(newNode->right);
            if(newNode->val!=value) return false;
        }
        return true;
    }
};