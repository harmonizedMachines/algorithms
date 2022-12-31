class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        queue<vector<int>> q;
        q.push({0});
        while (!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            if (curr.back() == graph.size() - 1){
                paths.push_back(curr);
            } else {
                for (int next: graph[curr.back()]){
                    vector<int> newpath(curr.begin(), curr.end());
                    newpath.push_back(next);
                    q.push(newpath);
                }
            }
        }
        return paths;
    }
};