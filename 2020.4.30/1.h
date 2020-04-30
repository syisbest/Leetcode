class Solution {
public:
    bool isHappy(int n) {
        map<int,int> visit;
        while(true){
            if(n==1)    return true;
            if(visit[n]==1) return false;
            visit[n]=1;
            n=getNext(n);
        }
        return false;
    }
    int getNext(int number){
        int sum=0;
        int n;
        while(number){
            n=number%10;
            sum=sum+n*n;
            number/=10;
        }
        return sum;
    }
};