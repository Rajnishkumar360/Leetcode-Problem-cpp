class Solution {
public:
    bool prime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int result =0;
        for(int i=left;i<=right;i++){
            int countOnes =0;
            int num = i;
            while(num>0){
                countOnes+=(num & 1);
                num >>=1;
            }
            if(prime(countOnes)) result++;
        }
        return result;
    }
};
