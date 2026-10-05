class Solution {
public:
    int helper(int i1,int j1,int i2,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        int j2 = i1+j1-i2;
        if(i1>=n || j1>=n || i2>=n || j2>=n) return -1e9;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e9;
        if(dp[i1][j1][i2] != -1) 
               return dp[i1][j1][i2];
        if(i1==n-1 && j1 == n-1) return grid[i1][j1];
        int cherris;
        if(i1==i2 && j1==j2)
          cherris = grid[i1][j1];
          else
          cherris = grid[i1][j1] + grid[i2][j2];
          int a = helper(i1,j1+1,i2,n,grid,dp);
          int b = helper(i1,j1+1,i2+1,n,grid,dp);
          int c = helper(i1+1,j1,i2,n,grid,dp);
          int d = helper(i1+1,j1,i2+1,n,grid,dp);
          int best = max({a,b,c,d});
          return dp[i1][j1][i2] = cherris + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(n, vector<int>(n, -1))
        );
        int ans =  helper(0,0,0,n,grid,dp);
        return max(0,ans);
    }
};