//dp
class Solution {
public:
    int waysToChange(int n) {
        int coins[4]={1,5,10,25};
        vector<int> f(n+1);
        f[0]=1;
        for(int i=0;i<4;i++)
        {
            int coin=coins[i];
            for(int j=coin;j<=n;j++)
            {
                f[j]+=f[j-coin];
                if(f[j]>1000000007)
                    f[j]%=1000000007;
            }
        }
        return f[n];
    }
};