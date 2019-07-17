struct BSTNode{
    int val;
    int count;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x):val(x),count(0),left(NULL),right(NULL){}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
/*
解题思路：
二叉查找树
时间复杂度：O(nlogn),空间复杂度：O(n)
*/
        vector<BSTNode*> node_vec;
        vector<int> counts;
        vector<int> result;
        for(int i=nums.size()-1;i>=0;i--){
            node_vec.push_back(new BSTNode(nums[i]));
        }
        counts.push_back(0);
        for(int i=1;i<node_vec.size();i++){
            int count_smaller=0;
            BST_insert(node_vec[0],node_vec[i],count_smaller);
            counts.push_back(count_smaller);
        }
        for(int i=node_vec.size()-1;i>=0;i--){
            delete node_vec[i];
            result.push_back(counts[i]);
        }
        return result;
    }
    void BST_insert(BSTNode* node,BSTNode* insert_node,int& count_smaller){
        if(insert_node->val<=node->val){
            node->count++;
            if(node->left){
                BST_insert(node->left,insert_node,count_smaller);
            }
            else{
                node->left=insert_node;
            }
        }
        else{
            count_smaller+=node->count+1;
            if(node->right){
                BST_insert(node->right,insert_node,count_smaller);
            }
            else{
                node->right=insert_node;
            }
        }
    }
};