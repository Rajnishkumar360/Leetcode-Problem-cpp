class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0;
        int currSum = 0;
        int maxSum = 0;
        for (int j=0;j<n;j++) {
            while (st.count(nums[j])) {
                st.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            currSum += nums[j];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};