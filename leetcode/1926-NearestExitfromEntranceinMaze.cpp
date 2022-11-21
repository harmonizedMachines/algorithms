class Solution {
public:
    int displacement[5] = {0, 1, 0, -1, 0};
    int m, n;
    
    int bfs(vector<vector<char>>& maze, int startRow, int startCol){
        queue<array<int, 3>> queue;
        queue.push({startRow, startCol, 0});
        maze[startRow][startCol] = '+';
        while (!queue.empty()){
            auto [row1, col1, step] = queue.front();
            queue.pop();
            for (int i = 0; i < 4; ++i) {
                int row = row1 + displacement[i], col = col1 + displacement[i + 1];
                if (row < 0 || row == n || col < 0 || col == m || maze[row][col] == '+') {
                    continue;
                }
                if (row == 0 || row == n - 1 || col == 0 || col == m - 1){
                    return step + 1;
                }
                maze[row][col] = '+';
                queue.push({row, col, step + 1});
            }   
        }
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size(), m = maze[0].size();
        return bfs(maze, entrance[0], entrance[1]);
    }
};