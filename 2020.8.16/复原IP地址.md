#### [复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

**有效的 IP 地址** 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 `0`），整数之间用 `'.' `分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 **有效的** IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 **无效的** IP 地址。

 

**示例 1：**

```
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

**示例 2：**

```
输入：s = "0000"
输出：["0.0.0.0"]
```

**示例 3：**

```
输入：s = "1111"
输出：["1.1.1.1"]
```

**示例 4：**

```
输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
```

**示例 5：**

```
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

 

**提示：**

- `0 <= s.length <= 3000`
- `s` 仅由数字组成

```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(ans, s, "", 0);
        return ans;       
    }
    void dfs(vector<string>& ans, string s, string cur, int count) {
        if(count == 4 && s.size() == 0) {
            cur.pop_back();
            ans.push_back(cur);
            return ;
        }
        if(count == 4 && s.size() != 0) {
            return ;
        }
        int len = s.size();
        for(int i = 1; i <= 3 && i <= len; i++) {
            string ss = s.substr(0, i);
            int num = stoi(ss);
            if(to_string(num).size() != ss.size())    return ;
            if(num >= 0 && num <= 255) {
                string temp = cur;
                cur = cur + ss + '.';
                dfs(ans, s.substr(i), cur, count+1);
                cur = temp;
            }
        }
    }
};
```

