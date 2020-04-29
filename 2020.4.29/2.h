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
    TreeNode* dfs(vector<int>& nums,int left,int right){
        if(left>right)  return nullptr;
        int mid=(left+right)/2;
        TreeNode* midNode=new TreeNode(nums[mid]);
        midNode->left=dfs(nums,left,mid-1);
        midNode->right=dfs(nums,mid+1,right);
        return midNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};