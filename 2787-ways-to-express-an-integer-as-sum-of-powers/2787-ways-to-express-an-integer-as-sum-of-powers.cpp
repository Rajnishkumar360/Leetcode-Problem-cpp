class Solution {
public:
    const int MOD = 1e9+7;
    int helper(int i,int cap,int x,vector<vector<int>>&dp){
        if(cap==0) return 1;
        if(i==0) return 0;
        if(dp[i][cap]!=-1) return dp[i][cap];
        int skip = helper(i-1,cap,x,dp);
        int pick = 0;
        long long val = 1;
        for(int j=0;j<x;j++) val *=i;
        if(val<=cap){
            pick = helper(i-1,cap-val,x,dp);
        }
        return dp[i][cap] = (skip+pick) % MOD;
    }
    int numberOfWays(int n, int x) {
        int maxBase = 1;
        while(pow(maxBase,x)<=n) maxBase++;
        maxBase--;
        vector<vector<int>>dp(maxBase+1,vector<int>(n+1,-1));
        return helper(maxBase,n,x,dp);
    }
};