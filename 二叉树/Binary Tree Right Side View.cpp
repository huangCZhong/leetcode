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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root){
            return result;
        }
        int cur=1;
        int next=0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* node=Q.front();
            Q.pop();
            cur--;
            if(node->left){
                Q.push(node->left);
                next++;
            }
            if(node->right){
                Q.push(node->right);
                next++;
            }
            if(cur==0){
                result.push_back(node->val);
                cur=next;
                next=0;
            }
            
        }
        return result;
    }
};