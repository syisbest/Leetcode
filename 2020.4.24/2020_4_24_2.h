class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x=board.size();
        int y=board[0].size();
        int ii,jj;
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                if(board[i][j]=='R')
                {
                    ii=i;
                    jj=j;
                }
        int up=ii,down=ii,left=jj,right=jj;
        int ans=0;
        while(up>=0)
        {
            if(board[up][jj]=='B')
                break;
            if(board[up][jj]=='p')
            {
                ans++;
                break;
            }
            up--;
        }
        while(down<x)
        {
            if(board[down][jj]=='B')
                break;
            if(board[down][jj]=='p')
            {
                ans++;
                break;
            }
            down++;
        }
        while(left>=0)
        {
            if(board[ii][left]=='B')
                break;
            if(board[ii][left]=='p')
            {
                ans++;
                break;
            }
            left--;
        }
        while(right<y)
        {
            if(board[ii][right]=='B')
                break;
            if(board[ii][right]=='p')
            {
                ans++;
                break;
            }
            right++;
        }
        return ans;
    }
};