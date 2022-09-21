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
    
    vector<vector<int>>& flip(vector<vector<int>>& mat, int row, int col){
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
        return mat;
    }
    
    int flipOrNot(vector<vector<int>> mat, int row, int col){
        if (col == n) row++, col = 0;
        if (row == m) return check_zero(mat) ? 0: 100000;
        
        int notflipcount = flipOrNot(mat, row, col + 1);
        int flipcount = flipOrNot(flip(mat, row, col), row, col + 1) + 1;
        return min(flipcount, notflipcount);
    }
    
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int res = flipOrNot(mat, 0, 0);
        return res >= 100000 ? -1: res;
    }
};