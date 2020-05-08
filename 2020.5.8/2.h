/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//结果前插和后插
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        if(!root)   return ans;
        queue<TreeNode*> temp;
        temp.push(root);
        int step=0;
        while(!temp.empty()){
            int tsize=temp.size();
            v.clear();
            step++;
            for(int i=0;i<tsize;i++){
                root=temp.front();
                temp.pop();
                if(step%2==1)
                    v.push_back(root->val);
                else
                    v.insert(v.begin(),root->val);
                if(root->left)  temp.push(root->left);
                if(root->right) temp.push(root->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};




//双向队列
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        if(!root)   return ans;
        deque<TreeNode*> temp;
        temp.push_back(root);
        int step=0;
        while(!temp.empty()){
            int tsize=temp.size();
            v.clear();
            step++;
            for(int i=0;i<tsize;i++){
                if(step%2==1){
                    root=temp.front();  temp.pop_front();
                    if(root->left)  temp.push_back(root->left);
                    if(root->right) temp.push_back(root->right);
                }
                else{
                    root=temp.back();  temp.pop_back();
                    if(root->right) temp.push_front(root->right);
                    if(root->left)  temp.push_front(root->left);
                }
                v.push_back(root->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};