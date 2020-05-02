//超时
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans=0;
        for(int i=K;i<=A.size();i++){
            ans+=solute(A,i,K);
        }
        return ans;
    }
    int solute(vector<int>& A,int n,int K){
        int cnt=0;
        int i=0,j=n-1;
        while(j<A.size()){
            set<int> count;
            for(int k=i;k<=j;k++){
                count.insert(A[k]);
            }
            if(count.size()==K)
                cnt++;
            i++;j++;
        }
        return cnt;
    }
};



class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int len = A.size();
        vector<int> counts(len + 1, 0);
        int left = 0;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (counts[A[i]]++ == 0) ++cnt;
            while (cnt > K) {
                if (--counts[A[left]] == 0) cnt--;
                left++;
            }
            int t = left;
            if (cnt == K) {
                while (cnt == K) {
                    if (--counts[A[t]] == 0) --cnt;
                    t++;
                    ans++;
                }
                for (int j = left; j < t; j++) {
                    if (counts[A[j]]++ == 0) cnt++;
                }
            }
        }
        return ans;
    }
};
