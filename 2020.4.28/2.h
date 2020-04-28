class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        auto it=ans.begin();
        for(it;it!=ans.end();it++){
            if(it->second==1)
                return it->first;
        }
        return 0;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x>>i)&1;
            }
            ans |= (cnt%3)<<i;
        }
        return ans;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seeonce=0,seetwice=0;
        for(int n:nums){
            seeonce=(n^seeonce)&(~seetwice);
            seetwice=(n^seetwice)&(~seeonce);
        }
        return seeonce;
    }
};