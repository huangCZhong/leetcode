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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> result;
        generate(root,path,result,0,sum);
        return result;   
    }
    
    void generate(TreeNode* node,vector<int>& path,vector<vector<int>>& result,int pathSum,int sum){
        if(node==NULL){
            return;
        }
        
        pathSum+=node->val;
        path.push_back(node->val);
        if(node->left==NULL&&node->right==NULL&&pathSum==sum){
            result.push_back(path);
        }
        generate(node->left,path,result,pathSum,sum);
        generate(node->right,path,result,pathSum,sum);
        pathSum-=node->val;
        path.pop_back();
    }
};