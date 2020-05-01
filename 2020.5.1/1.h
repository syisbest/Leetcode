class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        while(len1<len2){
            num1="0"+num1;
            len1++;
        }
        while(len2<len1){
            num2="0"+num2;
            len2++;
        }
        int flag=0;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans=num1;
        for(int i=0;i<len2;i++){
            ans[i]=((num1[i]-'0')+(num2[i]-'0')+flag)%10+'0';
            flag=((num1[i]-'0')+(num2[i]-'0')+flag)/10;
        }
        if(flag==1)
            ans=ans+"1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};