class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
/*
解题思路：
首先对数组排序，然后依次对数组中的每个元素应用双指针法

时间复杂度：O(n2) 空间复杂度：O(1)
*/
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(left!=i+1&&nums[left]==nums[left-1]) left++;
                else if(right!=n-1&&nums[right]==nums[right+1]) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else if(nums[i]+nums[left]+nums[right]>0) right--;
                else{
                    result.push_back(vector<int> {nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};