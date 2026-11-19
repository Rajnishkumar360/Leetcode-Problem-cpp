class Solution {
public:
    long long gcd(long long a,long long b){
        while(b){
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    bool check(long long mid,int divisor1,int divisor2,int uniqueCnt1,int uniqueCnt2){
        long long lcm = (1LL*divisor1/gcd(divisor1,divisor2))*divisor2;
        long long c1 = mid-mid/divisor1;
        long long c2 = mid-mid/divisor2;
        long long c = mid-mid/lcm;
        return c1>=uniqueCnt1 && c2>=uniqueCnt2 && c>=(long long)uniqueCnt1 + uniqueCnt2;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low = 1;
        long long high = 1e18;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid,divisor1,divisor2,uniqueCnt1,uniqueCnt2)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};