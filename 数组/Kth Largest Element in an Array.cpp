class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
/*
解题思路：
构建一个最小堆，当堆的大小小于k时直接把数组元素插入堆，否则当数组元素大于堆顶元素时，将堆顶元素弹出，然后插入数组元素。最后返回堆顶元素。

时间复杂度：O(n*log(k)) 空间复杂度：O(k)
*/
        priority_queue<int,vector<int>,greater<int>> h;
        if(nums.size()==0){
            return 0;
        }
        
        for(int i=0;i<nums.size();i++){
            if(h.size()<k){
                h.push(nums[i]);
            }
            else{
                if(h.top()<nums[i]){
                    h.pop();
                    h.push(nums[i]);
                }
            }
        }
        return h.top();
    }
};