class Solution {
public:
    int findDuplicate(vector<int>& nums) {
/*
解题思路:定义begin=1,end=n，mid=(begin+end)/2。统计数组中位于区间[begin,mid]的元素个数count。如果count大于(mid-begin+1)，说明该区间内存在重复元素，令end=mid，继续查找。如果count==(mid-begin+1),说明区间[mid+1,end]存在重复元素，令begin=mid+1，继续查找。
时间复杂度：O(nlogn)，空间复杂度：O(1)
*/
        int res=0;
        findCore(nums,1,nums.size()-1,res);
        return res;
    }
    void findCore(vector<int>& nums, int begin,int end,int& res){
        int count;
        int mid=(begin+end)/2;
        count=Count(nums,begin,mid);
        if(begin==end&&count>1){
            res=begin;
            return;
        }
        if(count>mid-begin+1){
            findCore(nums,begin,mid,res);
        }
        else{
            findCore(nums,mid+1,end,res);
        }
    }
    
    int Count(vector<int>& nums, int begin,int end){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=begin&&nums[i]<=end){
                sum++;
            }
        }
        return sum;
    }
};