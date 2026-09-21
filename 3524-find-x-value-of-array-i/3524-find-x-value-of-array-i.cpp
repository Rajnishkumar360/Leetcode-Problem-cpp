class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k,0);
        vector<long long>dp(k,0);
        for(int num:nums){
            vector<long long>newDp(k,0);
            newDp[num % k]++;
            for(int r=0;r<k;r++){
                if(dp[r]>0){
                    int newR = (r*1LL*num) %  k;
                    newDp[newR] += dp[r];
                }
            }
            for(int r=0;r<k;r++){
                result[r] += newDp[r];
            }
            dp = newDp;
        }
        return result;
    }
};