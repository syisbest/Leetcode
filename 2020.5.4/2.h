class Solution {
public:
    int jump(vector<int>& nums) {
        int len=nums.size(),maxDis=0,end=0,step=0;
        for(int i=0;i<len-1;i++){
            if(i<=maxDis){
                maxDis=max(maxDis,i+nums[i]);
                if(i==end){
                    end=maxDis;
                    step++;
                }
            }
        }
        return step;
    }
};