/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> temp;
        temp.push(root);
        temp.push(root);
        while(!temp.empty()){
            TreeNode* r1=temp.front();
            temp.pop();
            TreeNode* r2=temp.front();
            temp.pop();
            if(r1==NULL&&r2==NULL)  continue;
            if(r1==NULL||r2==NULL)  return false;
            if(r1->val!=r2->val)    return false;
            temp.push(r1->left);
            temp.push(r2->right);
            temp.push(r1->right);
            temp.push(r2->left);
        }
        return true;
    }
};

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);
    }
    bool isSymmetric(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL)  return true;
        if(r1==NULL||r2==NULL)  return false;
        return (r1->val==r2->val)&&isSymmetric(r1->left,r2->right)&&isSymmetric(r1->right,r2->left);
    }
};