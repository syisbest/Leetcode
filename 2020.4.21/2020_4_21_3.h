class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int man1=0,count1=0;
        int man2=0,count2=0;
        for(int num:nums)
        {
            if(num==man1)
            {
                count1++;
                continue;
            }
            if(num==man2)
            {
                count2++;
                continue;
            }
            if(count1==0)
            {
                man1=num;
                count1=1;
                continue;
            }
            if(count2==0)
            {
                man2=num;
                count2=1;
                continue;
            }
            count1--;
            count2--;
        }
        count1=count2=0;
        for(int num:nums)
        {
            if(num==man1)
                count1++;
            else if(num==man2)
                count2++;
        }
        int len=nums.size();
        nums.clear();
        if(count1>len/3)
            nums.push_back(man1);
        if(count2>len/3)
            nums.push_back(man2);
        return nums;
    }
};