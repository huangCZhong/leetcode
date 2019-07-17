class Solution {
public:
    int majorityElement(vector<int>& nums) {
/*
解题思路：
数组中出现次数超过一半的数字，说明该数字的出现次数比其他数字出现次数总和还要多。

时间复杂度：O(n),空间复杂度：O(1)
*/
        int result=nums[0];
        int time=1;
        for(int i=1;i<nums.size();i++){
            if(time==0){
                result=nums[i];
                time=1;
            }
            else if(result==nums[i]){
                time++;
            }
            else{
                time--;
            }
        }
        return result;
    }
};