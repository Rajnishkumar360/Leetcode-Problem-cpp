class Solution {
public:
    void backtrack(vector<int>&candidates,int target,int start,vector<int>&currArr,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(currArr);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) continue;
            currArr.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i,currArr,ans);
            currArr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> currArr;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,currArr,ans);
        return ans;
        
    }
};