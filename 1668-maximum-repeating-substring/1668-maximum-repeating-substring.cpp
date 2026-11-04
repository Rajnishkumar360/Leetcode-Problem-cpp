class Solution {
public:
    int helper(int i,string& sequence, string& word,vector<int>&dp){
        int n = sequence.size();
        int m = word.size();
        if(i+m>n) return 0;
        if(dp[i]!=-1) return dp[i];
        if(sequence.substr(i,m)==word)
        return dp[i] = 1+helper(i+m,sequence,word,dp);
        
        return dp[i] = 0;
    }
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int ans =0;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans = max(ans,helper(i,sequence,word,dp));
        }
        return ans;
    }
};