class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int x=matrix.size();
        if(x==0)    return 0;
        int y=matrix[0].size();
        if(y==0)    return 0;

        int intMatrix[x+1][y+1];
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                intMatrix[i+1][j+1]=matrix[i][j]-'0';
        for(int i=0;i<=y;i++)
            intMatrix[0][i]=0;
        for(int j=0;j<=x;j++)
            intMatrix[j][0]=0;
        int max=intMatrix[0][0];
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(intMatrix[i][j]==1)
                    intMatrix[i][j]=min(min(intMatrix[i-1][j-1],intMatrix[i][j-1]),intMatrix                                        [i-1][j])+1;
                if(intMatrix[i][j]>max)
                    max=intMatrix[i][j];
            }
        }
        return max*max;
    }
};