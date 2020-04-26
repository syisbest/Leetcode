/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans(0);
        ListNode *start=&ans;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                start->next=l1;
                l1=l1->next;
            }
            else
            {
                start->next=l2;
                l2=l2->next;
            }
            start=start->next;
        }
        start->next=l1?l1:l2;
        return ans.next;
    }
};