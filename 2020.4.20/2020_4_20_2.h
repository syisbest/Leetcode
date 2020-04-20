class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        multimap<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m.insert({nums[i], i});
        }
        auto b = m.begin(), e = --m.end();
        while(b != e){
            if(b->first + e->first < target){
                b++;
            }
            else if(b->first + e->first > target){
                e--;
            }
            else{
                break;
            }
        }
        return {b->second,e->second};
    }
};