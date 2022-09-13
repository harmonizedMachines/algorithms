class Solution {
public:
    void dfs(vector<vector<char>>& board, int n, int row, int col){
        int count = 0;
        for (int i = -1; i < 2; i++){
            if (i + row >= 0 && i + row < n){
                for (int j = -1; j < 2; j++){
                    if (j == 0 && i == 0){
                        continue;
                    }
                    if (j + col >= 0 && j + col < n){
                        if (board[row + i][col + j] == 'M'){
                            count = count + 1;
                        }
                    }
                }   
            }
        }
        if (count != 0){
            board[row][col] = '0' + count;
        } else {
            board[row][col] = 'B';
            for (int i = -1; i < 2; i++){
                for (int j = -1; j < 2; j++){
                    dfs(board, n, row + i, col + j);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        } else {
            dfs(board, board.size(), click[0], click[1]);
            return board;
        }
    }
};