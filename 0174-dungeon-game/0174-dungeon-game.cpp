class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&dungeon,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1) return max(1,1-dungeon[i][j]);
        if(i==n || j==m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = helper(i,j+1,n,m,dungeon,dp);
        int down = helper(i+1,j,n,m,dungeon,dp);
        int next = min(right,down);
        return dp[i][j] =  max(1,next-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,dungeon,dp);
    }
};