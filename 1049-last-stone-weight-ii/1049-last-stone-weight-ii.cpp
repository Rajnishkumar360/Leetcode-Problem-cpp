class Solution {
public:
    int helper(vector<int>& stones, int i, int sum, unordered_map<string,int>& dp, int cap) {
        if (i == stones.size()) {
            return abs(cap - 2 * sum);
        }
        string key = to_string(i) + "," + to_string(sum);
        if (dp.count(key)) return dp[key];
        int pick = helper(stones, i+1, sum + stones[i], dp, cap);
        int skip = helper(stones, i+1, sum, dp, cap);
        return dp[key] = min(pick, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int cap = accumulate(stones.begin(), stones.end(), 0);
        unordered_map<string,int> dp;
        return helper(stones, 0, 0, dp, cap);
    }
};
