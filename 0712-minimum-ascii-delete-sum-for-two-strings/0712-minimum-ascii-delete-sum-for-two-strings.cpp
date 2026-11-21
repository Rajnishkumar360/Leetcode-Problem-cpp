class Solution {
public:
    int helper(string &s1, string &s2, int i, int j,
               vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = helper(s1, s2, i - 1, j - 1, dp) + s1[i - 1];
        }
        else {
            int first = helper(s1, s2, i - 1, j, dp);
            int second = helper(s1, s2, i, j - 1, dp);
            if (first > second) {
                dp[i][j] = first;
            } else {
                dp[i][j] = second;
            }
        }
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1,
                               vector<int>(m + 1, -1));
        int common = helper(s1, s2, n, m, dp);
        int ans = 0;
        for (char ch : s1) {
            ans += ch;
        }
        for (char ch : s2) {
            ans += ch;
        }
        return ans - 2 * common;
    }
};