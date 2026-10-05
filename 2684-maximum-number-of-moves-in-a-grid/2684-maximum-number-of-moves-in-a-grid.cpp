class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(j==m-1) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       int ans = 0;
       if(j+1<m && grid[i][j+1]>grid[i][j]){
        ans = max(ans,1+helper(i,j+1,n,m,grid,dp));
       }
       if(i-1 >=0 && j+1 < m  && grid[i-1][j+1]>grid[i][j]){
        ans = max(ans,1+helper(i-1,j+1,n,m,grid,dp));
       }
       if(i+1<n && j+1 <m && grid[i+1][j+1]>grid[i][j]){
        ans = max(ans,1+helper(i+1,j+1,n,m,grid,dp));
       }
       return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,helper(i,0,n,m,grid,dp));
        }
        return ans;
    }
};