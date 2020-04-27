class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)  return -1;
        if(len==1&&nums[0]!=target) return -1;

        int i=0,j=len-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target)   return mid;
            if(nums[mid]>=nums[i]){
                if(target>=nums[i]&&target<nums[mid]){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            else{
                if(target>nums[mid]&&target<=nums[j])
                    i=mid+1;
                else    j=mid-1;
            }
        }
        return -1;
    }
};