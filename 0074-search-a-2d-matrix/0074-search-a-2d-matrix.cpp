class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return helper(matrix, target, 0, m*n - 1, n);
    }
    bool helper(vector<vector<int>>& matrix, int target, int left, int right, int n) {
        if (left > right) return false;
        int mid = left + (right - left) / 2;
        int row = mid / n;
        int col = mid % n;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) 
            return helper(matrix, target, mid+1, right, n);
        else 
            return helper(matrix, target, left, mid-1, n);
    }
};
