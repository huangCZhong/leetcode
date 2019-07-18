/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
/*
解题思路：用快慢指针找到链表的中点
时间复杂度：O(nlogn)，空间复杂度：O(n)
*/
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* pre=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        pre->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(fast);
        return root;
    }
};