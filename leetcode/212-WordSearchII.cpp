struct TrieNode{
    TrieNode* children[26] = {};
    string* s;
    void addword(string& word){
        TrieNode* curr = this;
        for (char c: word){
            c -= 'a';
            if (!curr->children[c]){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->s = &word;
    }
};

class Solution {
public:
    vector<string> res;
    int transpose[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<char>>& board, TrieNode* cur, int row, int col){
        if (col < 0 || row < 0 || col >= board[0].size() || 
            row >= board.size() || board[row][col] == '#' || !cur){
            return;
        }
        int c = board[row][col] - 'a';
        cur = cur->children[c];
        if (cur && cur->s){
            res.push_back(*cur->s);
            cur->s = NULL;
        }
        char original = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; ++i){
            dfs(board, cur, row + transpose[i], col + transpose[i+1]);
        }
        board[row][col] = original;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode t;
        for (auto& word: words){
            t.addword(word);
        }
        for (int row = 0; row < board.size(); ++row){
            for (int col = 0; col < board[0].size(); ++col){
                dfs(board, &t, row, col);
            }
        }
        return res;
    }
};