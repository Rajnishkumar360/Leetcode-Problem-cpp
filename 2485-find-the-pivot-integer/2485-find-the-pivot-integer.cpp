class Solution {
public:
    int pivotInteger(int n) {
        int Total = n*(n+1)/2;
        int forwardSum =0;
        for(int x=1;x<=n;x++){
            // int leftSum = x*(x+1)/2;
            // int rightSum = Total-(x-1)*x/2;
            // if(leftSum == rightSum) return x;
            forwardSum += x;
            int  backwardSum = Total-forwardSum+x;
            if(forwardSum==backwardSum) return x;
        }
        return -1;
    }
};