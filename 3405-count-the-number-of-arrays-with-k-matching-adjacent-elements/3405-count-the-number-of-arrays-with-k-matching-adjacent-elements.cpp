#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 100000;
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long fact[MAXN+1], invfact[MAXN+1];
long long modinv(long long a) {
    return modpow(a, MOD-2);
}
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invfact[n] = modinv(fact[n]);
        for (int i = n-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;
        int b = n - k;
        long long ways = nCr(n-1, b-1);
        ways = ways * m % MOD;
        ways = ways * modpow(m-1, b-1) % MOD;
        return (int)ways;
    }
};
