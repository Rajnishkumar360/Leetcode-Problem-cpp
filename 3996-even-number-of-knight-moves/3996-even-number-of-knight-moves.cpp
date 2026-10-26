class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int sx = start[0];
        int sy = start[1];
        int tx = target[0];
        int ty = target[1];
        return ((sx+sy)% 2) == ((tx+ty) % 2);
    }
};