class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = m ? matrix[0].size() : 0;
        int r = 0, c = n - 1;
        while(r<m && c>=0){
            if(matrix[r][c] == target){
                return true;
            }
            target < matrix[r][c] ? c-- : r++;
        }
        return false;
    }
};