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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
/*
解题思路：定义两个指针slow和fast，让fast先走n-1步，然后两个指针同时向前移动，直到fast指向尾部节点，此时slow就指向要删除的节点。
时间复杂度：O(n),空间复杂度：O(1)
*/
        if(!head){
            return nullptr;
        }
        
        ListNode new_head(-1);
        new_head.next=head;
        ListNode *slow=&new_head,*fast=&new_head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *delete_node=slow->next;
        slow->next=slow->next->next;
        delete delete_node;
        return new_head.next;
    }
};