#### [螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)

给定一个正整数 *n*，生成一个包含 1 到 *n*2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

**示例:**

```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```



```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        for(int start=0,end=n-1,num=1;start<=end;start++,end--){
            for(int j=start;j<=end;j++)   ans[start][j]=num++;
            for(int i=start+1;i<=end;i++)   ans[i][end]=num++;
            for(int j=end-1;j>=start;j--)   ans[end][j]=num++;
            for(int i=end-1;i>=start+1;i--) ans[i][start]=num++;
        }
        return ans;
    }
};
```

