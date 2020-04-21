// 使用map计数
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>(nums.size()/2))
                return nums[i];
        }
        return 0;
    }
};
*/

// 排序后输出中位数
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
*/

// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else
            {
                count--;
                if(count<0)
                {
                    candidate = num;
                    count = 1;
                }
            }
        }
        return candidate;
    }
};
