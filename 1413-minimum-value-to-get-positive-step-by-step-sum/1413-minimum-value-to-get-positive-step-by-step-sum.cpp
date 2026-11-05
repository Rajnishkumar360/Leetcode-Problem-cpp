class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix =0;
        int minValue =0;
        for(int x:nums){
            prefix += x;
            minValue = min(minValue,prefix);
        }
        return 1-minValue;
    }
};