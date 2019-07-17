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
    bool hasCycle(ListNode *head) {
/*
解题思路：快慢指针
时间复杂度：O(n),空间复杂度：O(1)
*/
        if(!head){
            return false;
        }
        ListNode* p1=head;
        ListNode* p2=p1->next;
        while(p1&&p2){
            if(p1==p2){
                return true;
            }
            else{
                p1=p1->next;
                p2=p2->next;
                if(p2){
                    p2=p2->next;
                }
            }
        }
        return false;
    }
};