class Solution {
public:
    long long C2(long long x) {
        if (x < 2) return 0;
        return x * (x - 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        long long L = limit;
        long long ans = C2(n + 2);
        ans -= 3 * C2(n - L + 1);
        ans += 3 * C2(n - 2 * L);
        ans -= C2(n - 3 * L - 1);

        return ans;
    }
};