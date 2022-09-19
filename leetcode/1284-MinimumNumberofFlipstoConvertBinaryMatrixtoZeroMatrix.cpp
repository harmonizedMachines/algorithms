class Solution {
public:
    int m, n;
    
    bool check_zero(vector<vector<int>>& mat){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void flip(vector<vector<int>>& mat, int row, int col){
        mat[row][col] ^= 1;
        if (row-1 >= 0){
            mat[row-1][col] ^= 1;
        }
        if (row+1 < m){
            mat[row+1][col] ^= 1;
        }
        if (col-1 >= 0){
            mat[row][col-1] ^= 1;
        }
        if (col+1 < n){
            mat[row][col+1] ^= 1;
        }
    }
    
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
    }
};