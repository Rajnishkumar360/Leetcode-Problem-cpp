class Solution {
public:
    bool helper(vector<int>& nums,int i,int cap,vector<vector<int>>&dp){
        if(cap == 0) return true;
        if(i<0) return false;
        if(dp[i][cap]!=-1) return dp[i][cap];
        bool pick = false;
        if(nums[i]<=cap){
            pick = helper(nums,i-1,cap-nums[i],dp);
        }
         bool skip = helper(nums,i-1,cap,dp);
         return dp[i][cap] = (pick || skip);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        int cap = sum/2;
        vector<vector<int>>dp(n,vector<int>(cap+1,-1));
        return helper(nums,n-1,cap,dp);
    }
};