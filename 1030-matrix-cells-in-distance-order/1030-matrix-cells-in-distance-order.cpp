#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({rCenter, cCenter});
        visited[rCenter][cCenter] = true;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            result.push_back({r, c});
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return result;
    }
};
