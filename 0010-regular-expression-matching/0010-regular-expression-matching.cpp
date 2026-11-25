class Solution {
public:
    bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (j < 0) {
            return false;
        }
        if (i < 0) {
            if (p[j] == '*') {
                return helper(i, j - 2, s, p, dp);
            }
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        bool ans = false;
        if (p[j] == '*') {
            ans = helper(i, j - 2, s, p, dp);
            if (j >= 1 && (s[i] == p[j - 1] || p[j - 1] == '.')) {
                ans = ans || helper(i - 1, j, s, p, dp);
            }
        } else {
            if (s[i] == p[j] || p[j] == '.') {
                ans = helper(i - 1, j - 1, s, p, dp);
            }
        }
        if (ans) {
            dp[i][j] = 1;
        } else {
            dp[i][j] = 0;
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};