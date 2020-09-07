#### [前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

给定一个非空的整数数组，返回其中出现频率前 ***k\*** 高的元素。

 

**示例 1:**

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```
输入: nums = [1], k = 1
输出: [1]
```

 

**提示：**

- 你可以假设给定的 *k* 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
- 你的算法的时间复杂度**必须**优于 O(*n* log *n*) , *n* 是数组的大小。
- 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
- 你可以按任意顺序返回答案。

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for(int &num : nums) {
            myMap[num]++;
        }
        vector<pair<int, int>> temp;
        for(auto &val : myMap) {
            temp.push_back(val);
        }
        vector<int> ans;
        qsort(0, temp.size() - 1, temp, ans, k);
        return ans;
    }
    void qsort(int start, int end, vector<pair<int, int>> &temp, vector<int> &ans, int k) {
        int pivot = temp[start].second;
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (temp[i].second >= pivot) {
                swap(temp[index + 1], temp[i]);
                index++;
            }
        }
        swap(temp[start], temp[index]);

        if (k <= index - start) {
            qsort(start, index - 1, temp, ans, k);
        } else {
            for (int i = start; i <= index; i++) {
                ans.push_back(temp[i].first);
            }
            if (k > index - start + 1) {
                qsort(index + 1, end, temp, ans, k - (index - start + 1));
            }
        }
    }
};
```

