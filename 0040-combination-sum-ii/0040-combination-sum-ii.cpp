class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& currArr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(currArr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1])continue;
            if (candidates[i] > target) break;
            currArr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currArr, ans);
            currArr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currArr;
        backtrack(candidates, target, 0, currArr, ans);
        return ans;
    }
};
