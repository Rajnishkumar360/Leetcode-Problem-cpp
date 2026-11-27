class Solution {
    public:
    int n;
    int m;
    int ans = 0;
    int helper(int i, int j,string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) {
            int result = 2 + helper(i + 1, j - 1, s, dp);
            if (i < n && j >= n) {
                ans = max(ans, result);
            }
            return dp[i][j] = result;
        }
        return dp[i][j] = max(helper(i + 1, j, s, dp), helper(i, j - 1, s, dp));
    }
    int longestPalindrome(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        string s = word1 + word2;
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        helper(0, len - 1, s, dp);
        return ans;
    }
};