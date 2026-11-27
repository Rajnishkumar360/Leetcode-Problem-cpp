class Solution {
public:
    // int helper(int i, int j, vector<int>& nums,vector<vector<int>>&dp) {
    //     if (i == nums.size()) {
    //         return 0;
    //     }
    //     if(dp[i][j+1]!=-1) return dp[i][j+1];
    //     int notTake = helper(i + 1, j, nums,dp);
    //     int take = 0;
    //     if (j == -1 || nums[i] > nums[j]) {
    //         take = 1 + helper(i + 1, i, nums,dp);
    //     }
    //     if (take > notTake) {
    //         return  dp[i][j+1] = take;
    //     } else {
    //         return dp[i][j+1] = notTake;
    //     }
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return helper(0, -1, nums,dp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0;i< n;i++) {
            for (int j = 0;j<i;j++) {
                if (nums[i]>nums[j]) {
                    dp[i]= max(dp[i], dp[j] + 1);
                    maxi= max(maxi, dp[i]);
                }
            }
        }
        return maxi;
    }
};
    