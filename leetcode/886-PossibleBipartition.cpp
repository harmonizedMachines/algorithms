class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> adj(n + 1, vector<int>());
        for (auto& dislike: dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        for (int i = 1; i <= n; ++i){
            if (color[i] == 0){
                queue<int> q;
                color[i] = 1;
                q.push(i);
                while (!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for (int child: adj[curr]){
                        if (color[child] == color[curr]){
                            return false;
                        }
                        if (!color[child]){
                            q.push(child);
                            color[child] = color[curr] * -1;
                        }
                    }
                }
            }
        }
        return true;
    }
};