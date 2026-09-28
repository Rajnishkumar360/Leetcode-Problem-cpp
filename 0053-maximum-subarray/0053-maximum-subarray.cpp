class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>&dp){
        if(i==0) return nums[0];
        if(dp[i]!=INT_MIN) return dp[i];
        dp[i] = max(nums[i],nums[i]+helper(nums,i-1,dp));
        return dp[i];
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MIN);
        int ans = nums[0];
        for(int i=0;i<n;i++){
            ans = max(ans,helper(nums,i,dp));
        }
        return ans;
    }
};