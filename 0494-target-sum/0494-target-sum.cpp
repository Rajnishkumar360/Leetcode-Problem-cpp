class Solution {
public:
    int backtrack(vector<int>&nums,int target,int idx,int sum){
       if(idx==nums.size()){
        if (sum == target) {
            return 1;
        } else {
          return 0;
          }
       }
       int add = backtrack(nums,target,idx+1,sum+nums[idx]);
       int sub = backtrack(nums,target,idx+1,sum-nums[idx]);
       return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums,target,0,0);
    }
};