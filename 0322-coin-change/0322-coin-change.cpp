class Solution {
public:
    int helper(vector<int>& coins,int amount,int i,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(i==coins.size()) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int skip = helper(coins,amount,i+1,dp);
        int pick =1e9;
        if(coins[i]<=amount){
            pick = 1 + helper(coins,amount-coins[i],i,dp);
        }
        return dp[i][amount] = min(skip,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans =  helper(coins,amount,0,dp);
        return ans == 1e9 ? -1 : ans;
    }
};