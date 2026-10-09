class Solution {
public:
    int helper(int i1, int j1, int i2, int j2, int n, int m,
               vector<vector<int>>& grid,
               vector<vector<vector<vector<int>>>>& dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return INT_MIN;

        if (i1 == n - 1) {
            if (j1 == j2)
                return grid[i1][j1];
            else
                return grid[i1][j1] + grid[i2][j2];
        }

        if (dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];
        int cherry = 0;

        if (i1 == i2 && j1 == j2)
            cherry += grid[i1][j1];
        else
            cherry += grid[i1][j1] + grid[i2][j2];

  int a = helper(i1 + 1, j1, i2 + 1, j2 - 1, n, m, grid, dp);
  int b = helper(i1 + 1, j1, i2 + 1, j2 + 1, n, m, grid, dp);
  int c = helper(i1 + 1, j1, i2 + 1, j2, n, m, grid, dp);
  int d = helper(i1 + 1, j1 - 1, i2 + 1, j2 - 1, n, m,grid, dp);
  int e = helper(i1 + 1, j1 - 1, i2 + 1, j2, n, m, grid, dp);
  int f = helper(i1 + 1, j1 - 1, i2 + 1, j2 + 1, n, m, grid,dp);
  int g = helper(i1 + 1, j1 + 1, i2 + 1, j2 - 1, n, m, grid,dp);
  int h = helper(i1 + 1, j1 + 1, i2 + 1, j2, n, m, grid, dp);
  int k = helper(i1 + 1, j1 + 1, i2 + 1, j2 + 1, n, m, grid,dp);
        int best = max({a, b, c, d, e, f, g, h, k});
        return dp[i1][j1][i2][j2] = cherry + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(n, vector<int>(m, -1))));
        return helper(0, 0, 0, m - 1, n, m, grid, dp);
    }
};