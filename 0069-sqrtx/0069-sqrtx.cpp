class Solution {
public:
    int mySqrt(int n) {
        if(n==0) return 0;
        long long ans = 1;
        int  low = 1;
        int high = n;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long val = mid *mid;
            if(val <=n){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
};