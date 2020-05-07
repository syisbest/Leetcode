/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//dfs
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)  return false;
        else
            return check(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    bool check(TreeNode* s,TreeNode* t){
        if(s==NULL&&t==NULL)    return true;
        if((s==NULL&&t!=NULL)||(s!=NULL&&t==NULL)||(s->val!=t->val))    return false;
        else    return check(s->left,t->left)&&check(s->right,t->right);
    }
};