#include<iostream>
#include<vector>
using namespace std;

//动态规划，O(n2)
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        vector<int> value(n, 0);
        value[0]=1;
        for(int i=1;i<n;i++)
        {
            int k=value[i];
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    k=value[j]+1;
                else
                    k=1;
                if(k>value[i])
                    value[i]=k;
            }
        }
        int max=value[0];
        for(int i=0;i<n;i++)
            if(value[i]>max)
                max=value[i];
        return max;
    }
};
*/

// 贪心，二分查找，O(nlogn) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=1;
        int n=nums.size();
        if(n==0)    return 0;
        vector<int> value(n+1,0);
        value[len]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>value[len])
            {
                len++;
                value[len]=nums[i];
            }
            else
            {
                int low=1,high=len,pos=0;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    if(nums[i]>value[mid])
                    {
                        low=mid+1;
                        pos=mid;
                    }
                    else
                        high=mid-1;
                }
                value[pos+1]=nums[i];
            }
        }
        return len;
    }
};

