class Solution {
public:
    int helper(vector<int>&nums,int goal){
        int n = nums.size();
        if(goal < 0) return 0;
        int count = 0;
        long long sum =0;
        int i=0;
        for(int j=0;j<n;j++){
            sum += nums[j];
            while(sum>goal){
                sum -= nums[i];
                i++;
            }
           count += (j-i+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal-1);
    }
};