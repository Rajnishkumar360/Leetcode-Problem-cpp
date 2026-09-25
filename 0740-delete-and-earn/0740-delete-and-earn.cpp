class Solution {
public:
    int helper(vector<int>& points, int i, vector<int>& dp) {
        if (i <= 0) return 0;
        if (dp[i] != -1) return dp[i];
        int take = points[i] + helper(points, i-2, dp);
        int notTake = helper(points, i-1, dp);
        return dp[i] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal+1,0);
        for (int x: nums) points[x] += x;
        vector<int> dp(maxVal+1,-1);
        return helper(points, maxVal, dp);
    }
};
