class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int m = 2*n;
        int oddSum = 0;
        int evenSum = 0;
        for(int i=1;i<=m;i++){
            if(i % 2 ==0){
                oddSum += i;
            }
            evenSum += i;
        }
        return gcd(oddSum,evenSum);
    }
};