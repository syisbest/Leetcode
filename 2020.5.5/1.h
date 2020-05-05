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
    bool isValidBST(TreeNode* root) {
        return isTrue(root,LONG_MIN,LONG_MAX);
    }
    bool isTrue(TreeNode* root,long long min,long long max){
        if(root==nullptr)   return true;
        if(root->val>=max||root->val<=min)  return false;
        return isTrue(root->left,min,root->val)&&isTrue(root->right,root->val,max);
    }
};