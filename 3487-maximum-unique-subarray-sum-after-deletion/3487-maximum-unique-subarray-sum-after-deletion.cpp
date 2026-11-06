class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        if (maxi < 0) return maxi;
        unordered_set<int> st;
        int sum = 0;
        for (int x : nums) {
            if (x > 0 && st.find(x) == st.end()) {
                sum += x;
                st.insert(x);
            }
        }
        return sum;
    }
};