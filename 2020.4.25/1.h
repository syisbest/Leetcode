//调用函数
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        do{
            v.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return v;
    }
};

//回溯法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len=nums.size();
        dfs(ans,nums,0,len);
        return ans;  
    }
    void dfs(vector<vector<int>>& ans,vector<int>& nums,int cut,int len){
        if(cut==len)
        {
            ans.push_back(nums);
            return ;
        }
        for(int i=cut;i<len;i++)
        {
            swap(nums[cut],nums[i]);
            dfs(ans,nums,cut+1,len);
            swap(nums[cut],nums[i]);
        }
    }
};