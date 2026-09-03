class Solution {
public:
    int smallestDivisor(vector<int>& nums, int k) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long sum =0;
            for(int small : nums){
                sum += (small + mid-1)/mid;
            }
            if(sum<=k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};