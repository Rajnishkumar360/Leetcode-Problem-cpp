class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //              if(nums[i]==nums[j] && abs(i-j)<=k){
    //                 return true;
    //              }
                
    //         }
    //     }
    //     return false;
           int n = nums.size();
           unordered_map<int,int>mp;
           for(int i=0;i<n;i++){
             if(mp.count(nums[i])){
                int prevIdx = mp[nums[i]];
                if(i-prevIdx <= k){
                    return true;
                }
             }
             mp[nums[i]] = i;
           }
           return false;
    }
};