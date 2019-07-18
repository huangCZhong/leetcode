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
    vector<vector<int>> levelOrder(TreeNode* root) {
/*
解题思路：队列
时间复杂度：O(n)，空间复杂度：O(n)
*/
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        int cur=1;
        int next=0;
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> tmp;
        while(!Q.empty()){
            TreeNode* node=Q.front();
            Q.pop();
            cur--;
            tmp.push_back(node->val);
            if(node->left){
                Q.push(node->left);
                next++;
            }
            if(node->right){
                Q.push(node->right);
                next++;
            }
            if(cur==0){
                res.push_back(tmp);
                tmp.clear();
                cur=next;
                next=0;
            }
        }
        return res;
    }
};