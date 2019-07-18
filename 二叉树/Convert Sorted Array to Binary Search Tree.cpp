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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
/*
解题思路：递归
时间复杂度：O(n)，空间复杂度：O(n)
*/
        if(nums.size()==0){
            return NULL;
        }
        return generate(nums,0,nums.size()-1);
    }
    
    TreeNode* generate(vector<int>& nums,int begin,int end){
        if(begin>end){
            return NULL;
        }
        int mid=(begin+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        if(mid>begin){
            root->left=generate(nums,begin,mid-1);
        }
        if(mid<end){
            root->right=generate(nums,mid+1,end);
        }
        return root;
    }
};