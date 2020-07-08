#### [从上到下打印二叉树 II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]
```

 

**提示：**

1. `节点总数 <= 1000`

```c++
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
        queue<TreeNode*> myQueue;
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        myQueue.push(root);
        while(!myQueue.empty()){
            int len=myQueue.size();
            vector<int> res;
            for(int i=0;i<len;i++){
                TreeNode* node=myQueue.front();
                myQueue.pop();
                if(node->left)  myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
                res.push_back(node->val);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
```

