class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums1[i] >= nums1[i - 1]) {
                int candidate = dp1[i - 1] + 1;
                if (candidate > dp1[i]) {
                    dp1[i] = candidate;
                }
            }
            if (nums1[i] >= nums2[i - 1]) {
                int candidate = dp2[i - 1] + 1;
                if (candidate > dp1[i]) {
                    dp1[i] = candidate;
                }
            }
            if (nums2[i] >= nums1[i - 1]) {
                int candidate = dp1[i - 1] + 1;
                if (candidate > dp2[i]) {
                    dp2[i] = candidate;
                }
            }
            if (nums2[i] >= nums2[i - 1]) {
                int candidate = dp2[i - 1] + 1;
                if (candidate > dp2[i]) {
                    dp2[i] = candidate;
                }
            }
            if (dp1[i] > ans) {
                ans = dp1[i];
            }
            if (dp2[i] > ans) {
                ans = dp2[i];
            }
        }
        return ans;
    }
};