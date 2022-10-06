class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vert(n, vector<int>(m)), hori(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                vert[i][j] = grid[i][j] + ((i && grid[i][j]) ? vert[i-1][j]: 0);
                hori[i][j] = grid[i][j] + ((j && grid[i][j]) ? hori[i][j-1]: 0);
            }
        }
        for (int l = min(m, n); l > 0; l--){
            for (int i = 0; i < n - l + 1; i++){
                for (int j = 0; j < m - l + 1; j++){
                    if (min({vert[i+l-1][j], vert[i+l-1][j+l-1], hori[i+l-1][j+l-1], hori[i][j+l-1]}) >= l){
                        return l * l;
                    }
                }
            }
        }
        return 0;
    }
};