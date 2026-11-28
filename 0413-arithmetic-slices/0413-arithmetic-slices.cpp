class Solution {
public:
    int helper(vector<int>& nums, int i) {
        if (i < 2) {
            return 0;
        }
        if (nums[i]-nums[i - 1]!=nums[i - 1]-nums[i - 2]) {
            return 0;
        } else {
            return 1 + helper(nums,i - 1);
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i =2;i<n;i++) {
            count = count + helper(nums, i);
        }
        return count;
    }
};