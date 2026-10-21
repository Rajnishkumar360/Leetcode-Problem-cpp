class Solution {
public:
    bool checkPrime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int val =0;val<=100;val++){
            int count =0;
            for(int i=0;i<n;i++){
                if(nums[i]==val) count++;
            }
            if(checkPrime(count)) return true;
        }
        return false;
    }
};