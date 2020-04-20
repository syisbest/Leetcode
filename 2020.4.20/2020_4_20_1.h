#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char> >& grid,int i,int j)
    {
        int x=grid.size();
        int y=grid[0].size();
        grid[i][j]='0';

        if(i-1>=0&&grid[i-1][j]=='1')   dfs(grid,i-1,j);
        if(i+1<x&&grid[i+1][j]=='1')    dfs(grid,i+1,j);
        if(j-1>=0&&grid[i][j-1]=='1')   dfs(grid,i,j-1);
        if(j+1<y&&grid[i][j+1]=='1')    dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char> >& grid) {
        int x=grid.size();
        if(x==0)    return 0;
        int y=grid[0].size();

        int ans=0;
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }

        return ans;
    }
};
