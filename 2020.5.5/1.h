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
    bool isValidBST(TreeNode* root) {
        return isTrue(root,LONG_MIN,LONG_MAX);
    }
    bool isTrue(TreeNode* root,long long min,long long max){
        if(root==nullptr)   return true;
        if(root->val>=max||root->val<=min)  return false;
        return isTrue(root->left,min,root->val)&&isTrue(root->right,root->val,max);
    }
};


//迭代
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> temp;
        long long lastVal=LONG_MIN;
        while(!temp.empty()||root!=nullptr){
            while(root!=nullptr){
                temp.push(root);
                root=root->left;
            }
            root=temp.top();
            temp.pop();
            if(root->val<=lastVal)    return false;
            lastVal=root->val;
            root=root->right;
        }
        return true;
    }
};