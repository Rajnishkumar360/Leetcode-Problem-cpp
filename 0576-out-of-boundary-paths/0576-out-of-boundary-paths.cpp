class Solution {
public:
    const int MOD = 1e9+7;
    int helper(int i,int j,int n,int m,int maxM,vector<vector<vector<int>>>&dp){
        if(i<0 || i>=n ||j<0 || j>=m) return 1;
        if(maxM==0) return 0;
        if(dp[i][j][maxM]!=-1) return dp[i][j][maxM];
        int x1 = helper(i,j+1,n,m,maxM-1,dp);
        int x2 = helper(i,j-1,n,m,maxM-1,dp);
        int x3 = helper(i-1,j,n,m,maxM-1,dp);
        int x4 = helper(i+1,j,n,m,maxM-1,dp);
        return dp[i][j][maxM] = ((x1%MOD+x2%MOD)%MOD + (x3%MOD + x4%MOD)%MOD) %MOD;

    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(maxMove+1,-1)));
        return helper(startRow,startColumn,n,m,maxMove,dp);
    }
};