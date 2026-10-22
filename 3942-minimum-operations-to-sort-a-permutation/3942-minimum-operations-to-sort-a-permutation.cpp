
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        bool inc = true;
        bool dec = true;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (nums[next]!= (nums[i] + 1) % n) {
                inc = false;
            }
            if (nums[next]!= (nums[i] - 1 + n) % n) {
                dec = false;
            }
        }
        if (inc) {
            return min(zero, n - zero + 2);
        }
        if (dec) {
            int k = n - 1 - zero;
            return 1 + min(k, n - k);
        }
        return -1;
    }
};
