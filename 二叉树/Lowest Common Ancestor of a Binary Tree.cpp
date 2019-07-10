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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        vector<TreeNode*> node_p_path;
        vector<TreeNode*> node_q_path;
        int finish=0;
        preorder(root,p,path,node_p_path,finish);
        path.clear();
        finish=0;
        preorder(root,q,path,node_q_path,finish);
        int path_length=0;
        if(node_p_path.size()<node_q_path.size()){
            path_length=node_p_path.size();
        }
        else{
            path_length=node_q_path.size();
        }
        TreeNode* result;
        for(int i=0;i<path_length;i++){
            if(node_p_path[i]==node_q_path[i]){
                result=node_p_path[i];
            }
        }
        return result;
    }
private:
    void preorder(TreeNode* node,TreeNode* search,vector<TreeNode*> &path,vector<TreeNode*> &result,int &finish){
        if(!node||finish){
            return;
        }
        path.push_back(node);
        if(node==search){
            finish=1;
            result=path;
        }
        preorder(node->left,search,path,result,finish);
        preorder(node->right,search,path,result,finish);
        path.pop_back();
    }
};