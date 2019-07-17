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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
/*
时间复杂度：O(N)，空间复杂度：O(1)
*/
        int length=n-m+1;
        ListNode* result=head;
        ListNode* preNode=NULL;
        while(head&&--m){
            preNode=head;
            head=head->next;
        }
        ListNode* modify_tail=head;
        ListNode* new_head=NULL;
        while(head&&length){
            ListNode* next=head->next;
            head->next=new_head;
            new_head=head;
            head=next;
            length--;
        }
        modify_tail->next=head;
        if(preNode){
            preNode->next=new_head;
        }
        else{
            result=new_head;
        }
        return result;
    }
};