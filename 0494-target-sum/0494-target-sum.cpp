class Solution {
public:
    int helper(vector<int>& nums, int i, int sum, int target, unordered_map<string,int>& dp) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        string key = to_string(i) + "," + to_string(sum);
        if (dp.count(key)) return dp[key];
        int add = helper(nums, i+1, sum + nums[i], target, dp);
        int subtract = helper(nums, i+1, sum - nums[i], target, dp);
        return dp[key] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> dp;
        return helper(nums, 0, 0, target, dp);
    }
};
