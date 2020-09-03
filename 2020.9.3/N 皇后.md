#### [N 皇后](https://leetcode-cn.com/problems/n-queens/)

*n* 皇后问题研究的是如何将 *n* 个皇后放置在 *n*×*n* 的棋盘上，并且使皇后彼此之间不能相互攻击。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)

上图为 8 皇后问题的一种解法。

给定一个整数 *n*，返回所有不同的 *n* 皇后问题的解决方案。

每一种解法包含一个明确的 *n* 皇后问题的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

 

**示例：**

```
输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
```

 

**提示：**

- 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

```c++
class Solution {
private:
    unordered_set<int> columns;   //记录已有皇后的列
    unordered_set<int> leftDowns;  //记录右上到坐下的斜线
    unordered_set<int> rightDowns; //记录左上到右下的斜线

    vector<vector<string>> anss;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp(n, -1);   //临时保存一种结果
        helper(n, 0, temp);
        return anss;
    }
    void helper(int n, int row, vector<int>& temp) {
        if(n == row) {
            vector<string> ans = getAns(n, temp);
            anss.push_back(ans);
            return ;
        }
        else {
            for(int i = 0; i < n; i++) {
                if(columns.find(i) != columns.end())
                    continue;
                int leftDown = i + row;
                if(leftDowns.find(leftDown) != leftDowns.end())
                    continue;
                int rightDown = i - row;
                if(rightDowns.find(rightDown) != rightDowns.end())
                    continue;
                
                temp[row] = i;
                columns.insert(i);
                leftDowns.insert(leftDown);
                rightDowns.insert(rightDown);
                helper(n, row + 1, temp);
                temp[row] = -1;
                columns.erase(i);
                leftDowns.erase(leftDown);
                rightDowns.erase(rightDown);
            }
        }
    }
    vector<string> getAns(int n, vector<int>& temp) {
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            string row(n, '.');
            row[temp[i]] = 'Q';
            ans.push_back(row);
        }
        return ans;
    }
};
```

