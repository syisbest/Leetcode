#### [全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

给定一个可包含重复数字的序列，返回所有不重复的全排列。

**示例:**

```
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

```c++
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> visit(nums.size(), 0);
        help(nums, 0, visit);
        return ans;
    }
    void help(vector<int>& nums, int index, vector<int>& visit) {
        if(index == nums.size()) {
            ans.push_back(temp);
            return ;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visit[i] || i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])
                continue;
            temp.push_back(nums[i]);
            visit[i] = 1;
            help(nums, index + 1, visit);
            visit[i] = 0;
            temp.pop_back();
        }
    }
};
```

