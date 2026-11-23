class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int INF = m + n;
        vector<vector<int>> dp(m, vector<int>(n, INF));
        // Pass 1: top-left to bottom-right (uses top & left)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                   if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        // Pass 2: bottom-right to top-left (uses bottom & right)
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j + 1 < n) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
        return dp;
    }
};