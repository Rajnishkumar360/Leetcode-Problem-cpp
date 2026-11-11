class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        long long score = 0;
        int i=0;
        for(int j=0;j<n;j++){
            sum += nums[j];
            while(sum*(j-i+1) >=k){
                sum -= nums[i];
                i++;
            }
             score += (j-i+1);
        }
        return score;
    }
};