class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        if(!len)    return 0;
        vector<int> v(len);
        v[0]=1;
        for(int i=1;i<len;i++)
        {
            if(nums[i]>nums[i-1])
                v[i]=v[i-1]+1;
            else
                v[i]=1;
        }
        int max=v[0];
        for(int value:v)
        {
            if(value>max)
                max=value;
        }
        return max;
    }
};

//不需要开数组
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        if(!len)    return 0;
        int value=1;
        int max=1;
        for(int i=1;i<len;i++)
        {
            if(nums[i]>nums[i-1])   value+=1;
            else    value=1;
            if(value>max)
                max=value;
        }
        return max;
    }
};