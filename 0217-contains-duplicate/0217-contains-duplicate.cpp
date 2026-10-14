class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>1) return true;
        }
        return false;
        // int n = nums.size();
        // int count = 0;
        // for(int i=1;i<=n;i++){
        //     if(nums[i]==nums[i-1]){
        //         count++;
        //     }
        //     if(count >1){
        //         return true;
        //     }
        // }
        // return false;
    }
};