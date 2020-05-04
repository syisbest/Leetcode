class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if(len<=1)  return true;
        int maxDis=0;
        for(int i=0;i<len-1;i++){
            if(i<=maxDis){
                maxDis=max(maxDis,i+nums[i]);
                if(maxDis>=len-1)   return true;
            }
        }
        return false;
    }
};