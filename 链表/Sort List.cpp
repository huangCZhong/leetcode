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
    ListNode* sortList(ListNode* head) {
/*
解题思路：将列表拆分再融合
时间复杂度：O(nlogn),空间复杂度：O(1)
*/
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        
        return Merge(sortList(head),sortList(fast));
    }
    
    ListNode* Merge(ListNode* L1,ListNode* L2){
        if(!L1){
            return L2;
        }
        if(!L2){
            return L1;
        }
        ListNode* merge_head;
        if(L1->val<L2->val){
            merge_head=L1;
            merge_head->next=Merge(L1->next,L2);
        }
        else{
            merge_head=L2;
            merge_head->next=Merge(L1,L2->next);
        }
        return merge_head;
    }
};