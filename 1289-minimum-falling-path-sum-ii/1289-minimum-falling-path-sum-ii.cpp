class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int j=0;j<m;j++){
            dp[n-1][j] = grid[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int ans = INT_MAX;
                for(int k=0;k<m;k++){
                    if(k!=j){
                        ans = min(ans,dp[i+1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + ans;
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;
    }
};