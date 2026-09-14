class Solution {
public:
    long long floor_div(long long a, long long b) {
        long long q = a / b;
        long long r = a % b;
        if (r != 0 && ((r > 0) != (b > 0)))
            q--;

        return q;
    }
    long long ceil_div(long long a, long long b) {
        return -floor_div(-a, b);
    }
    long long countPairs(vector<int>& a, vector<int>& b, long long x) {
        long long cnt = 0;
        int n = b.size();
        for (long long v : a) {
            if (v > 0) {
                // v * y <= x
                // y <= floor(x / v)
                long long limit = floor_div(x, v);
                cnt += upper_bound(b.begin(), b.end(), limit) - b.begin();
            }
            else if (v < 0) {
                // v * y <= x
                // y >= ceil(x / v)
                long long limit = ceil_div(x, v);
                cnt += b.end() - lower_bound(b.begin(), b.end(), limit);
            }
            else {
                // 0 * y <= x
                if (x >= 0)
                    cnt += n;
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1,vector<int>& nums2,long long k) {
        long long low = min({
            1LL * nums1[0] * nums2[0],
            1LL * nums1[0] * nums2.back(),
            1LL * nums1.back() * nums2[0],
            1LL * nums1.back() * nums2.back()
        });
        long long high = max({
            1LL * nums1[0] * nums2[0],
            1LL * nums1[0] * nums2.back(),
            1LL * nums1.back() * nums2[0],
            1LL * nums1.back() * nums2.back()
        });
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cnt = countPairs(nums1, nums2, mid);
            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};