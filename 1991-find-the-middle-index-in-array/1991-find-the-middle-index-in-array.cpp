class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int rightSum = 0;
        int leftSum = 0;
        for(int x:nums){
            sum += x;
        }
        for(int i=0;i<n;i++){
            rightSum = sum - leftSum -nums[i];
            if(rightSum == leftSum)
              return i;
            leftSum += nums[i];
        }
       
        return -1;
    }
};