class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int i) {
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size() || board[row][col] == '.' || board[row][col] != word[i++]) {
            return false;
        }
        if (i == word.size()){
            return true;
        }
        char c = board[row][col];
        board[row][col] = '.';
        bool res = dfs(board, word, row+1, col, i) || dfs(board, word, row-1, col, i) || dfs(board, word, row, col+1, i) || dfs(board, word, row, col-1, i);
        board[row][col] = c;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (dfs(board, word, row, col, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};