/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//O(k2n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=nullptr;
        for(int i=0;i<lists.size();i++){
            ans=mergeKLists(lists[i],ans);
        }
        return ans;
    }
    ListNode* mergeKLists(ListNode* l1,ListNode* l2){
        ListNode begin(0);
        ListNode* start=&begin;
        while(l1&&l2){
            if(l1->val<=l2->val){
                start->next=l1;
                l1=l1->next;
            }
            else{
                start->next=l2;
                l2=l2->next;
            }
            start=start->next;
        }
        start->next=l1?l1:l2;
        return begin.next;
    }
};


//采用分治O(nklogk)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left==right) return lists[left];
        if(left>right)  return nullptr;
        int mid=(left+right)/2;
        return mergeKLists(merge(lists,left,mid),merge(lists,mid+1,right));
    }
    ListNode* mergeKLists(ListNode* l1,ListNode* l2){
        ListNode begin(0);
        ListNode* start=&begin;
        while(l1&&l2){
            if(l1->val<=l2->val){
                start->next=l1;
                l1=l1->next;
            }
            else{
                start->next=l2;
                l2=l2->next;
            }
            start=start->next;
        }
        start->next=l1?l1:l2;
        return begin.next;
    }
};