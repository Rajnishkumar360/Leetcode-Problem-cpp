class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans =0;
        // consider all node is root denoted as i
        for(int i=1;i<=n;i++){
            ans += helper(i-1,dp)*helper(n-i,dp);
        }
        return dp[n] = ans;
    }

    int solve(int n){
        vector<int>dp(n+1,0); // tabulation
        dp[0] = 1;
        dp[1] = 1;
        // i as a no of node
        for(int i=2;i<=n;i++){
            // j as a node
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        // vector<int>dp(n+1,-1);
        // return helper(n,dp);
        return solve(n);
    }
};