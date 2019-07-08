class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
/*
解题思路：
首先用map记录数组中每个元素的下标，然后依次遍历数组中的每个元素，求该元素与目标之间的差值，如果该差值存在于数组中，并且该差值与当前元素不是同一个元素时，当前元素与差值的下标便是结果。

时间复杂度：O(n2)，空间复杂度：O(n)
*/
        std::map<int,int> nums_map;
        std::vector<int> result;
        for(int i=0;i<nums.size();i++){
            nums_map[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(nums_map.find(complement)!=nums_map.end()&&nums_map[complement]!=i){
                result.push_back(i);
                result.push_back(nums_map[complement]);
                break;
            }
        }
        return result;
    }
};