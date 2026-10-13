class Solution {
public:
    int helper(vector<int>&nums,int i,int rem,vector<vector<int>>& dp){
        if(i==nums.size()){
            return(rem == 0 ? 0:INT_MIN);
        }
        if(dp[i][rem]!=INT_MIN) return dp[i][rem];
        int skip = helper(nums,i+1,rem,dp);
        int pick = nums[i] + helper(nums,i+1,(rem+nums[i])%3,dp);
        return dp[i][rem] = max(skip,pick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,INT_MIN));
        return helper(nums,0,0,dp);
    }
};