class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;
            for (int j = i; j < n; j++) {
                long long val = nums[j];
                if (prod > 25200) {
                    break;
                }
                prod = prod * val;
                g = gcd(g, val);
                l = lcm(l, val);
                if (prod == l * g) {
                    int len = j - i + 1;
                    if (len > ans) {
                        ans = len;
                    }
                }
            }
        }
        return ans;
    }
};