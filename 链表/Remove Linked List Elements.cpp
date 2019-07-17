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
    ListNode* removeElements(ListNode* head, int val) {
/*
解题思路：利用指针的指针
时间复杂度：O(n)，空间复杂度：O(1)
*/
        ListNode** tmp=&head;
        while(*tmp){
            if((*tmp)->val==val) (*tmp)=(*tmp)->next;
            else{
                tmp=&((*tmp)->next);
            }
        }
        return head;
    }
};