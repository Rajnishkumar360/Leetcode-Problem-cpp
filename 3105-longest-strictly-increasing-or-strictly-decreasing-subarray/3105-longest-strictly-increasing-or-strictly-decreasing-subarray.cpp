class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int len = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    len++;
                    ans = max(ans, len);
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int len = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j - 1]) {
                    len++;
                    ans = max(ans, len);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};