class Solution {
public:
    void solve(vector<int>& nums, int startIdx, vector<int>& tem, vector<vector<int>>& ans) {
        if (tem.size() >= 2) {
            ans.push_back(tem);
        }
        unordered_set<int> usedAtLevel;
        for (int i = startIdx; i < (int)nums.size(); i++) {
            if (usedAtLevel.find(nums[i]) != usedAtLevel.end()) {
                continue;
            }
            bool canTake = false;
            if (tem.empty()) {
                canTake = true;
            } else {
                if (nums[i] >= tem.back()) {
                    canTake = true;
                }
            }
            if (canTake) {
                usedAtLevel.insert(nums[i]);
                tem.push_back(nums[i]);
                solve(nums, i + 1, tem, ans);
                tem.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tem;
        solve(nums, 0, tem, ans);
        return ans;
    }
};