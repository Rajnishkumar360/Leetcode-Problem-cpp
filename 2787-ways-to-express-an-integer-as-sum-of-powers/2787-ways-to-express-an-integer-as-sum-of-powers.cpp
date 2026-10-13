class Solution {
public:
    const int MOD = 1e9+7;
    int powerx;
    int helper(int n,int ind,vector<vector<int>>&dp){
        if(n==0) return 1;
        int power = 1;
        for(int i=0;i<powerx;i++)
            power *=ind;
        if(power>n)
            return 0;
        if(dp[n][ind]!=-1) return dp[n][ind];
        int skip = helper(n,ind+1,dp);
        int pick = helper(n-power,ind+1,dp);
        return  dp[n][ind]= (skip + pick) % MOD;
    }
        int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        powerx = x;
        return helper(n,1,dp);
        
    }
};
    