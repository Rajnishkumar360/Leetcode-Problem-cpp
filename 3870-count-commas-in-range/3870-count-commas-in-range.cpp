class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long st = 1;
        int commas = 0;
        while (st <= n) {
            long long end = st * 1000 - 1;
            if (end > n) end = n;
            if (commas > 0) {
                ans += (end - st + 1) * commas;
            }
            st *= 1000;
            commas++;
        }

        return ans;
    }
};