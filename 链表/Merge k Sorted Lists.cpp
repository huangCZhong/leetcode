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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        //ListNode* head=Merge(lists[0],lists[1]);
        //for(int i=2;i<lists.size();i++){
        //    head=Merge(head,lists[i]);
        //}
        //return head;
        return me(lists,0,lists.size()-1);
    }
    
    ListNode* Merge(ListNode* L1,ListNode* L2){
        if(!L1){
            return L2;
        }
        if(!L2){
            return L1;
        }
        ListNode* merge_head;
        if(L1->val<=L2->val){
            merge_head=L1;
            merge_head->next=Merge(L1->next,L2);
        }
        else{
            merge_head=L2;
            merge_head->next=Merge(L1,L2->next);
        }
        return merge_head;
    }
    
    ListNode* me(vector<ListNode*>& lists,int m,int n){
        if(m==n){
            return lists[m];
        }
        if(n-m==1){
            return Merge(lists[m],lists[n]);
        }
        return Merge(me(lists,m,m+(n-m)/2),me(lists,m+(n-m)/2+1,n));
    }
};