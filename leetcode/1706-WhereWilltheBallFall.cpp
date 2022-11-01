class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size(), -1);
        for (int col = 0; col < grid[0].size(); ++col){
            int currcol = col;
            for (int row = 0; row < grid.size(); ++row){
                int nextcol = currcol + grid[row][currcol];
                if (nextcol < 0 || nextcol == grid[0].size() || grid[row][currcol] != grid[row][nextcol]){
                    res[col] = -1;
                    break;
                }
                res[col] = nextcol;
                currcol = nextcol;
            }
        }
        return res;
    }
};