class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
         int l=0,r=n-1;
        // while part was creating err plxxxxxzzzzzzzzz check :/
        // while(l<=r){
        //    swap(matrix[l++],matrix[r--]);
        // l++;
        // r--;
        // }
        // FRIST INTERCHANGING ROWS CUZ IT IS EASY
         for(int i=0;i<n/2;i++){
            swap(matrix[i],matrix[n-i-1]);
        }
        
        for(int i=0;i<n;i++){
            for(int j = i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       
        
    }
};