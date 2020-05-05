/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    void helper(TreeNode* root,vector<int>& ans){
        if(root!=nullptr){
            if(root->left!=nullptr){
                helper(root->left,ans);
            }
            ans.push_back(root->val);
            if(root->right!=nullptr){
                helper(root->right,ans);
            }
        }
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        while(root!=nullptr||!temp.empty()){
            while(root!=nullptr){
                temp.push(root);
                root=root->left;
            }
            root=temp.top();
            ans.push_back(root->val);
            temp.pop();
            root=root->right;
        }
        return ans;
    }
};