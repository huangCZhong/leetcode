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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/*
解题思路：双指针
时间复杂度：O(n)，空间复杂度：O(1)
*/
        int lenA=length(headA);
        int lenB=length(headB);
        ListNode *pA=headA;
        ListNode *pB=headB;
        if(lenA>=lenB){
            int diff=lenA-lenB;
            while(diff){
                pA=pA->next;
                diff--;
            }
        }
        else{
            int diff=lenB-lenA;
            while(diff){
                pB=pB->next;
                diff--;
            }
        }
        while(pA&&pB){
            if(pA==pB){
                return pA;
            }
            pA=pA->next;
            pB=pB->next;
        }
        return NULL;
    }
    int length(ListNode *head){
        int sum=0;
        while(head){
            sum++;
            head=head->next;
        }
        return sum;
    }
};