class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int m;
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        m=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            if(m<dp[i]){
                m=dp[i];
            }
        }
        return m;
    }
};