//双循环O(n2),超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int cut=0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                    cut++;
            }
            ans+=cut;
        }
        return ans;
    }
};

//归并排序O(nlogn)
class Solution {
public:
   int count=0;
    void merge_sort(vector<int>& nums,int x,int y,vector<int>& temp)
    {
        if(y-x>1)
        {
            int mid=(x+y)/2;
            int p=x,q=mid,i=x;
            merge_sort(nums,x,mid,temp);
            merge_sort(nums,mid,y,temp);
            while(p<mid||q<y)
            {
                if(p>=mid||(q<y&&nums[p]>nums[q]))
                {
                    temp[i++]=nums[q++];
                    count+=mid-p;
                }
                else
                    temp[i++]=nums[p++];
            }
            for(i=x;i<y;i++)
                nums[i]=temp[i];
        }
    }
    int reversePairs(vector<int>& nums) {
        int len=nums.size();
        if(len<2)   return 0;
        vector<int> temp(nums);
        merge_sort(nums,0,len,temp);
        return count;
    }
};