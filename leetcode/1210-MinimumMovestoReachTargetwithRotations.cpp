class Solution {
public:
    int m, n, steps;
    bool canRotate(vector<vector<int>>& grid, int row, int col){
        return (row + 1 < m) && (col + 1 < n) && !grid[row][col+1] && !grid[row+1][col] &&
            !grid[row+1][col+1];
    }
    
    bool canGoDown(vector<vector<int>>& grid, int row, int col, bool hori){
        if (hori){
            return (row + 1 < m) && !grid[row+1][col] && !grid[row+1][col+1];
        }
        return (row + 2 < m) && !grid[row+2][col];
    }
    
    bool canGoRight(vector<vector<int>>& grid, int row, int col, bool hori){
        if (!hori){
            return (col + 1 < n) && !grid[row][col+1] && !grid[row+1][col+1];
        }
        return (col + 2 < n) && !grid[row][col+2];
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), steps = 0;
        queue<array<int, 3>> q1, q2;
        q1.push({0, 0, true});
        while (!q1.empty()){
            while (!q1.empty()){
                auto& a = q1.front();
                if (a[0] == m - 1 && a[1] == n - 2) return steps;
                if ((grid[a[0]][a[1]] & (a[2] ? 2: 4)) == 0){
                    grid[a[0]][a[1]] |= a[2] ? 2: 4;
                    if (canRotate(grid, a[0], a[1])){
                        q2.push({a[0], a[1], a[2] ? false: true});
                    }
                    if (canGoDown(grid, a[0], a[1], a[2])){
                        q2.push({a[0]+1, a[1], a[2]});
                    }
                    if (canGoRight(grid, a[0], a[1], a[2])){
                        q2.push({a[0], a[1]+1, a[2]});
                    }
                }
                q1.pop();
            }
            ++steps;
            swap(q1, q2);
        }
        return -1;
    }
};