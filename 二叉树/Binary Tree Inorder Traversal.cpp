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
    vector<int> inorderTraversal(TreeNode* root) {
/*
解题思路：递归
时间复杂度：O(n),空间复杂度：O(n)
*/
        vector<int> res;
        generate(root,res);
        return res;
    }
    
    void generate(TreeNode* node, vector<int>& res){
        if(node==NULL){
            return;
        }
        generate(node->left,res);
        res.push_back(node->val);
        generate(node->right,res);
    }
};