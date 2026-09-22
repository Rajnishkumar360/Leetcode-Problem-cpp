class Solution {
public:
    bool backtrack(int idx, vector<int>& matchsticks, vector<int>& sides, int side) {
        if (idx == matchsticks.size()) {
            return sides[0] == side && sides[1] == side &&
                   sides[2] == side && sides[3] == side;
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];  
                if (backtrack(idx + 1, matchsticks, sides, side)) return true;
                sides[i] -= matchsticks[idx];    
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks) sum += x;
        if (sum % 4 != 0) return false;
        int side = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); 
        vector<int> sides(4, 0);
        return backtrack(0, matchsticks, sides, side);
    }
};
