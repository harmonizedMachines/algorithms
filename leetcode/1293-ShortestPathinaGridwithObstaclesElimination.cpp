class Solution {
public:
    int m, n;
    int bfs(int k, vector<vector<int>>& grid){
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        q.push({0, 0, 0, k});
        while (!q.empty()){
            vector<int> tmp = q.front();
            q.pop();
            if (tmp[0] < 0 || tmp[0] >= m || tmp[1] < 0 || tmp[1] >= n){
                continue;
            }
            if (tmp[0] == m - 1 && tmp[1] == n - 1){
                return tmp[2];
            }
            
            if (grid[tmp[0]][tmp[1]]){
                if (tmp[3]){
                    --tmp[3];
                } else {
                    continue;
                }
                
            }
            if (visited[tmp[0]][tmp[1]] != -1 && visited[tmp[0]][tmp[1]] >= tmp[3]){
                continue;
            }
            visited[tmp[0]][tmp[1]] = tmp[3];
            q.push({tmp[0]+1, tmp[1], tmp[2] + 1, tmp[3]});
            q.push({tmp[0], tmp[1]+1, tmp[2] + 1, tmp[3]});
            q.push({tmp[0], tmp[1]-1, tmp[2] + 1, tmp[3]});
            q.push({tmp[0]-1, tmp[1], tmp[2] + 1, tmp[3]});
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        return bfs(k, grid);
    }
};