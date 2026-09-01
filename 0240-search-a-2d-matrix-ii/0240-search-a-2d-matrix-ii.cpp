class Solution {
public:
    bool helper(vector<vector<int>>&matrix,int row,int col,int target){
        if(row>=matrix.size()||col < 0) return false;
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target){
            return helper(matrix,row+1,col,target);
        }
        return helper(matrix,row,col-1,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return helper(matrix,0,m-1,target);
    }
};