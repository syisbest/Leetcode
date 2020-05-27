#### [链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

 

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```

```c++
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int len=0;
        ListNode* p=head;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        int index=len-k;
        while(index){
            index--;
            head=head->next;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast=head;
        while(k){
            fast=fast->next;
            k--;
        }
        while(fast!=NULL){
            head=head->next;
            fast=fast->next;
        }
        return head;
    }
};
```

