class Solution {
public:
    bool prime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    string binaryRepresentation(int n) {
        string result = "";
        while (n > 0) {
            if (n % 2 == 1) result.push_back('1');
            else result.push_back('0');
            n /= 2;
        }
        return result;
    }

    int countPrimeSetBits(int left, int right) {
        int totalCount = 0;
        for (int i = left; i <= right; i++) {
            string ans = binaryRepresentation(i);
            int countOnes = 0;
            for (char c : ans) {
                if (c == '1') countOnes++;
            }
            if (prime(countOnes)) {
                totalCount++;
            }
        }
        return totalCount;
    }
};
