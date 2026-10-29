class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int diff = maxVal - minVal;
        int score = diff - 2*k;
        if (score < 0) score = 0;
        return score;
    }
};
