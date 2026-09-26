class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if (n == 2) {
            return stones[1] - stones[0];
        }
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = stones[1] - stones[0];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2], stones[i] - stones[i - 2]);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};