//O(n/2)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0)    return false;
        int cut=0;
        for(int i=1;i<=num/2;i++)
            if(num%i==0)
                cut+=i;
        return cut==num;
    }
};

//O(√2)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0)  return false;
        int cut=0;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                cut+=i;
                cut+=num/i;
                if(i*i==num) cut-=i;
            }
        }
        cut-=num;
        return num==cut;
    }
};