class Solution {
public:
    int helper(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return 0; 
        if (i < 0) return -1;     
        if (dp[i][target] != -2) return dp[i][target];
        int skip = helper(nums, i-1, target, dp);
        int pick = -1;
        if (nums[i] <= target) {
            int res = helper(nums, i-1, target - nums[i], dp);
            if (res != -1) pick = res + 1; 
        }
        return dp[i][target] = max(skip, pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -2));
        return helper(nums, n-1, target, dp);
    }
};
