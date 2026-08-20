class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        // Only store odd numbers
        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        // All even numbers except 2 are not prime
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        // Check only odd numbers
        for (int i = 3; i * i < n; i += 2) {

            if (isPrime[i]) {

                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 1; // count prime 2

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                ans++;
        }

        return ans;
    }
};