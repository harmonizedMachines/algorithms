class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination){
            return true;
        } 
        vector<int> visited(n, 0);
        unordered_map<int, vector<int>> e;
        for (auto& edge: edges){
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }
        queue<int> hi;
        hi.push(source);
        while (!hi.empty()){
            int now = hi.front();
            hi.pop();
            for (int i: e[now]){
                if (i == destination){
                    return true;
                }
                if (!visited[i]){
                    visited[i] = 1;
                    hi.push(i);
                }
            }
        }
        return false;
    }
};