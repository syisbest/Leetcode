//dp,O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>0) nums[i]+=nums[i-1];
            if(nums[i]>max) max=nums[i];
        }
        return max;
    }
};


//二分法 O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dichotomy(nums,0,nums.size()-1);
    }
    int dichotomy(vector<int>& nums,int left,int right){
        if(left==right) return nums[left];
        int mid=(left+right)/2;
        int leftMax=dichotomy(nums,left,mid);
        int rightMax=dichotomy(nums,mid+1,right);
        int midLeftSum=0,midLeftMax=nums[mid];
        for(int i=mid;i>=left;i--)
        {
            midLeftSum+=nums[i];
            midLeftMax=max(midLeftMax,midLeftSum);
        }
        int midRightSum=0,midRightMax=nums[mid+1];
        for(int i=mid+1;i<=right;i++)
        {
            midRightSum+=nums[i];
            midRightMax=max(midRightMax,midRightSum);
        }
        return max(max(leftMax,rightMax),midLeftMax+midRightMax);
    }
};