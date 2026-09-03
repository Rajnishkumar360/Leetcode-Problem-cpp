class Solution {
public:
    bool helper(vector<int>& bloomDay, int m, int k, int days) {
        int bouquet = 0, count = 0;
        for (int b : bloomDay) {
            if (b <= days) {
                count++;
                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(bloomDay, m, k, mid)) {
                ans = mid;         
                high = mid - 1;
            } else {
                low = mid + 1;     
            }
        }
        return ans;
    }
};
