class Solution {
public:
    int minMoves(vector<int>& nums) {
        map<int,int> freq;
        int maxVal = INT_MIN;
        for (int num : nums) {
            freq[num]++;
            maxVal = max(maxVal, num);
        }
        int count = 0;
        for (auto x : freq) {
            count += (maxVal - x.first) * x.second;
        }
        return count;
    }
};

