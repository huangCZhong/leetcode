class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int max=0;
        vector<int> dp(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            int temp=0;
            for(int j=1;j<i;j++){
                if(nums[i-1]>nums[j-1]&&temp<dp[j]){
                    temp=dp[j];
                }
            }
            dp[i]=temp+1;
            if(max<dp[i]) max=dp[i];
        }
        return max;
    }
};