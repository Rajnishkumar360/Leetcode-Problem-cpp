class Solution {
public:
    int helper(string &s,int i,vector<int>&dp){
        if(i==0) return 1;
        if(s[0]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int result = 0;
        int onedigit = s[i-1]-'0';
        if(onedigit>=1){
            result += helper(s,i-1,dp);
        }
        if(i>=2){
            int twodigit = (s[i-2]-'0') * 10 + (s[i-1]-'0');
            if(twodigit>=10 && twodigit<=26){
                result += helper(s,i-2,dp);
            }
        }
        return  dp[i] = result;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return helper(s,n,dp);
    }
};