class Solution {
public:
    vector<int> dp;
    vector<int> count;
    int solve(vector<int>& nums, int i) {
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = 1;
        count[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                int len = solve(nums, j) + 1;
                if (len > dp[i]) {
                    dp[i] = len;
                    count[i] = count[j];
                }
                else if (len == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        return dp[i];
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        count.assign(n, -1);
        //vector<int>dp(n,-1);
        // vector<int>count(n,-1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, solve(nums, i));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ans += count[i];
            }
        }
        return ans;
    }
};