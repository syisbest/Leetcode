class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        set<char> visit;
        int left=0;
        int max=0;
        for(int i=0;i<len;i++){
            while(visit.find(s[i])!=visit.end()){
                visit.erase(s[left]);
                left++;
            }
            visit.insert(s[i]);
            if(i-left+1>max)
                max=i-left+1;
        }
        return max;
    }
};