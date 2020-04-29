/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int top = gettop(mountainArr);
        int pos = halfSearch(mountainArr, 0, top+1, target); // [0,top+1)
        return pos>=0?pos:halfSearch(mountainArr, mountainArr.length()-1, top, target); 
        //(top,len-1]
    }
    int gettop(MountainArray &m){ // 获取山顶
        int left=0,right=m.length()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(m.get(mid-1)<m.get(mid)) left=mid;
            else right=mid;
            if(right-left==1)   break;
        }
        return left;
    }
    int halfSearch(MountainArray &m, int left, int right, int target){ // 二分查找
        for(int mid=(left+right)/2; abs(right-left)>1; mid=(left+right)/2)
            if(target < m.get(mid)) right=mid;
            else left=mid;
        return m.get(left)==target?left:-1;
    }
};