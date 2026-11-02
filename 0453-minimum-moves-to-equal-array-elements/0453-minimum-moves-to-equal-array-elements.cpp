class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int count  = INT_MAX;
        for(int num:nums){
            sum += num;
            count = min(count,num);
        }
        return (int)sum-(long long)n*count;
    }
};
