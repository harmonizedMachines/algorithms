class Solution {
private:
    int count;
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;

    int dfs(int node, vector<bool>& hasApple, int cost){
        if (visited[node]){
            return 0;
        }
        visited[node] = true;
        int childcost = 0;
        for (auto i: g[node]){
            childcost += dfs(i, hasApple, 2);
        }
        if (childcost == 0 && hasApple[node] == false){
            return 0;
        }
        return childcost + cost;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto& edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        return dfs(0, hasApple, 0);
    }
};