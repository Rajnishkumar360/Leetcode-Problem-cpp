
class Solution {
public:
    int helper(vector<int>& coins, int amount, int i,vector<vector<int>>&dp) {
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int skip = helper(coins, amount, i + 1,dp);
        int pick = 0;
        if (coins[i] <= amount) {
            pick = helper(coins, amount - coins[i], i,dp);
        }
        return dp[i][amount] = skip + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return helper(coins, amount, 0,dp);
    }
};
