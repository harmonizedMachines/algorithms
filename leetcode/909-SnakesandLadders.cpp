class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            for (int i = curr + 1; i <= min(curr + 6, n * n); ++i){
                int row = (i - 1) / n, col = (i - 1) % n;
                if (row & 1){
                    col = n - 1 - col;
                }
                row = n - 1 - row;
                int dest = board[row][col] == -1 ? i: board[row][col]; 
                if (dist[dest] == -1){
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
        }
        return dist.back();
    }
};