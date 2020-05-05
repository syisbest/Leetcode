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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    void helper(TreeNode* root,vector<int>& ans){
        if(root!=nullptr){
            ans.push_back(root->val);
            if(root->left!=nullptr){
                helper(root->left,ans);
            }
            if(root->right!=nullptr){
                helper(root->right,ans);
            }
        }
    }
};

//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        if(root==nullptr)   return ans;
        temp.push(root);
        while(!temp.empty()){
            root=temp.top();
            temp.pop();
            ans.push_back(root->val);
            if(root->right!=nullptr) temp.push(root->right);
            if(root->left!=nullptr) temp.push(root->left);
        }
        return ans;
    }
};