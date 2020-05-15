#### [和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

给定一个整数数组和一个整数 **k，**你需要找到该数组中和为 **k** 的连续的子数组的个数。

**示例 1 :**

```
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
```

**说明 :**

1. 数组的长度为 [1, 20,000]。
2. 数组中元素的范围是 [-1000, 1000] ，且整数 **k** 的范围是 [-1e7, 1e7]。

```c++
//O(n2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k)   ans++;
            }
        }
        return ans;
    }
};

//O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int count=0;
        mp[0]=1;
        int sum=0;
        for(int i:nums){
            sum+=i;
            if(mp.find(sum-k)!=mp.end())  count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
```

