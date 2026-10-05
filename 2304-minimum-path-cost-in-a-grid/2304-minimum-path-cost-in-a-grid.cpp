class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&moveCost,vector<vector<int>>&dp){
         if(i == n-1) return grid[i][j];
         if(dp[i][j]!=-1) return dp[i][j];
         int ans = INT_MAX;
         for(int k=0;k<m;k++){
            int cost = moveCost[grid[i][j]][k];
            ans = min(ans,cost+helper(i+1,k,n,m,grid,moveCost,dp));
         }
         return  dp[i][j] = grid[i][j] + ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       int ans = INT_MAX;
       for(int j=0;j<m;j++){
       ans = min(ans,helper(0,j,n,m,grid,moveCost,dp));
        }
       return ans;
    }
};