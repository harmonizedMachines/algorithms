class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n){
        if (board[row][col] != 'E'){
            return;
        }
        int count = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, 
                                          {0, -1}, {-1, 0}};
        for (auto dir: directions){
            if (row + dir[0] < 0 || row + dir[0] >= m){
                continue;
            }
            if (col + dir[1] < 0 || col + dir[1] >= n){
                continue;
            }
            if (board[row + dir[0]][col + dir[1]] == 'M'){
                count++;
            }
        }
        if (count){
            board[row][col] = '0' + count;
        } else{
            board[row][col] = 'B';
            for (auto dir: directions){
                if (row + dir[0] < 0 || row + dir[0] >= m){
                    continue;
                }
                if (col + dir[1] < 0 || col + dir[1] >= n){
                    continue;
                }
                dfs(board, row + dir[0], col + dir[1], m, n);
            }
        }
        
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1], m, n);
        return board;
    }
};