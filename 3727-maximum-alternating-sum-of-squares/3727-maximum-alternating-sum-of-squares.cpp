class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>temp;
        for(auto it:nums){
            temp.push_back(abs(it));
        }
        sort(temp.begin(),temp.end());
        int n  = nums.size();
        long long ans =0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans -= (1LL)*temp[i]*temp[i];
            }else{
                ans += (1LL)*temp[i]*temp[i];
            }
        }
        return ans;
    }
};