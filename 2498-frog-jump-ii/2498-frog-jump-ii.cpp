class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& stones, int i) {
        if (i == 0) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i == 1) {
            return dp[i] = stones[1] - stones[0];
        }
        return dp[i] = max(
            solve(stones, i - 2),
            stones[i] - stones[i - 2]
        );
    }
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        dp = vector<int>(n, -1);
        return max(solve(stones, n - 1), solve(stones, n - 2));
    }
};