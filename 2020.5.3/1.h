class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(ans,n,0);
        return ans;
    }
    void dfs(vector<int>& ans,int n,int k){
        //if(k>n) return ;
        if(k!=0)    ans.push_back(k);
        for(int i=0;i<=9;i++){
            if(k*10+i>0&&k*10+i<=n){
                dfs(ans,n,k*10+i);
            }
        }
    }
};