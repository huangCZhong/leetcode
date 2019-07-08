class Solution {
public:
    int findMin(vector<int>& nums) {
/*
解题思路：
1.定义一个变量min,初始化为nums[0]，这样可以保证当数组只有一个元素时，程序也能输出正确结果
2.定义begin和end分别指向数组的首尾元素
3.如果nums[begin]<nums[end],说明数组没有旋转，则数组第一个元素就是最小值。
4.如果nums[begin]>nums[end],说明数组进行了旋转，利用二分查找找到最小值。

时间复杂度：O(n),空间复杂度:O(1)
*/
        int min=nums[0];
        int begin=0;
        int end=nums.size()-1;
        if(nums[begin]<nums[end]){
            min=nums[0];
        }
        else{
            while(begin<end){
                int mid=(begin+end)/2;
                if(mid==begin){
                    min=nums[mid+1];
                    break;
                }
                if(nums[mid]>nums[begin]){
                    begin=mid;
                }
                else{
                    end=mid;
                }
            }
        }
        return min;
    }
};