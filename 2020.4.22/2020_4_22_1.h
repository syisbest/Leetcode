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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int counts=que.size();
            for(int i=0;i<counts;++i)
            {
                TreeNode* node=que.front();
                que.pop();

                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
                
                if(i==counts-1) ans.push_back(node->val);
            }
        }

        return ans;
    }
};