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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        if(!root)   return ans;
        queue<TreeNode*> temp;
        temp.push(root);
        int tsize;
        while(!temp.empty()){
            tsize=temp.size();
            v.clear();
            for(int i=0;i<tsize;i++){
                root=temp.front();
                temp.pop();
                v.push_back(root->val);
                if(root->left)  temp.push(root->left);
                if(root->right) temp.push(root->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};