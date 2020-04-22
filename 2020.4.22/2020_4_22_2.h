class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int flag=0;
        for(int i=0;i<A.size();i++)
        {
            flag=flag*2+A[i];
            flag%=5;
            if(flag==0) ans.push_back(true);
            else    ans.push_back(false);
        }
        return ans;
    }
};