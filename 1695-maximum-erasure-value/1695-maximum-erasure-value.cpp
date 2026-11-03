class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0, j = 0;
        int sum = 0;
        int ans = 0;
        while (j < n) {
            if (st.find(nums[j]) == st.end()) {
                st.insert(nums[j]);
                sum += nums[j];
                ans = max(ans, sum);
                j++;
            } else {
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};