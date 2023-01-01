class Solution {
private:
    int dir[5] = {0, -1, 0, 1, 0};
    int m, n, res = 0, startx, starty, endx, endy, count = 0, passed = 0;
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited){
        if (row < 0 || row == m || col < 0 || col == n || grid[row][col] == -1 || visited[row][col] == 1){
            return;
        }
        
        if (row == endy && col == endx){
            cout << passed << " " << count << endl;
            if (passed == count){
                ++res;
            }
            return;
        }
        visited[row][col] = 1;
        if (grid[row][col] == 0){
            ++passed;
        }
        for (int i = 0; i < 4; ++i){
            dfs(row + dir[i], col + dir[i + 1], grid, visited);
        }
        visited[row][col] = -1;
        if (grid[row][col] == 0){
            --passed;
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                switch (grid[i][j]){
                    case 0:
                        ++count;
                        break;
                    case 1:
                        startx = j, starty = i;
                        break;
                    case 2:
                        endx = j, endy = i;
                        break;
                }
            }
        }
        dfs(starty, startx, grid, visited);
        return res;
    }
};