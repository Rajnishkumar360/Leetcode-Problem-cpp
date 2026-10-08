class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&grid,int& ans,vector<vector<int>>&dp){
        if(i>=n || j>=m) return INT_MIN;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int maxValue = grid[i][j];
        if(j+1 < m){
            int right = helper(i,j+1,n,m,grid,ans,dp);
            ans = max(ans,right-grid[i][j]);
            maxValue = max(maxValue,right);
        }
        if(i+1 < n){
            int down  = helper(i+1,j,n,m,grid,ans,dp);
            ans = max(ans,down-grid[i][j]);
            maxValue = max(maxValue,down);
        }
        return dp[i][j] = maxValue;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        helper(0,0,n,m,grid,ans,dp);
        return ans;
    }
};