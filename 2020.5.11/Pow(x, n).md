#### [ Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

实现 [pow(*x*, *n*)](https://www.cplusplus.com/reference/valarray/pow/) ，即计算 x 的 n 次幂函数。

**示例 1:**

```
输入: 2.00000, 10
输出: 1024.00000
```

**示例 2:**

```
输入: 2.10000, 3
输出: 9.26100
```

**示例 3:**

```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

**说明:**

- -100.0 < *x* < 100.0
- *n* 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

```c++
//取巧写法，借用exp(nlog(x))=xn
class Solution {

public:

  double myPow(double x, int n) {

​    if(x>0)

​      return exp(n*log(x));

​    else{

​      if(n%2==0)

​        return exp(n*log(-x));

​      else

​        return -exp(n*log(-x));

​    }

  }

};

// 递归快速幂
class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        return N>0?quickMul(x,N):1.0/quickMul(x,-N);
    }
    double quickMul(double x,long long n){
        if(n==0)    return 1.0;
        double y=myPow(x,n/2);
        if(n%2==0)  return y*y;
        else    return y*y*x;
    }
};

//按位操作迭代快速幂
class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        return N>0?quickMul(x,N):1.0/quickMul(x,-N);
    }
    double quickMul(double x,long long n){
        double ans=1.0;
        double cur=x;
        while(n){
            if(n%2==1){
                ans*=cur;
            }
            cur*=cur;
            n/=2;
        }
        return ans;
    }
};
```

