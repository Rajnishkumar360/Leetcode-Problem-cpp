class Solution {
public:
    int minMoves(vector<int>& nums) {
        map<int,int> freq;
        int maxVal = INT_MIN;
        for (int num : nums) {
            freq[num]++;
            maxVal = max(maxVal, num);
        }
        int moves = 0;
        for (auto p : freq) {
            moves += (maxVal - p.first) * p.second;
        }
        return moves;
    }
};

