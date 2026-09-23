class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total-x;
        if(target<0) return -1;
        if(target==0) return n;
        int sum = 0;
        int left =0;
        int maxLen = -1;
        for(int right=0;right<n;right++){
            sum +=nums[right];
            while(sum>target){
                sum -= nums[left++];
            }
            if(sum ==target){
                maxLen = max(maxLen,right-left+1);
            }
        }
        if(maxLen ==-1){
            return -1;
        }else{
            return n-maxLen;
        }
    }
};