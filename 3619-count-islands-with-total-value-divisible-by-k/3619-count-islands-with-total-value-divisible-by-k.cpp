class Solution {
public:
    long long helper(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        int n = grid.size();
        int m= grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j]==0 || visited[i][j]) return 0;
        visited[i][j] = true;
        long long sum = grid[i][j];
        sum += helper(grid,visited,i-1,j);
        sum += helper(grid,visited,i+1,j);
        sum += helper(grid,visited,i,j-1);
        sum += helper(grid,visited,i,j+1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    long long islandSum = helper(grid,visited,i,j);
                    if(islandSum % k==0) count++;
                }
            }
        }
        return count;
    }
};