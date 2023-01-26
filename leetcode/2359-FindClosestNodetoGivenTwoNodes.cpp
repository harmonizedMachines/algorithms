class Solution {
private:
    void dfs(vector<int>& edges, vector<int>& dist, int node){
        if (dist[node] == -1){
            dist[node] = 0;
        }
        int neighbor = edges[node];
        if (neighbor != -1 && dist[neighbor] == -1){
            dist[neighbor] = max(dist[node] + 1, 1);
            dfs(edges, dist, neighbor);
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(), -1), dist2(edges.size(), -1);
        dfs(edges, dist1, node1);
        dfs(edges, dist2, node2);
        int ans = INT_MAX, ansnode = -1;
        for (int i = 0; i < edges.size(); ++i){
            if (dist1[i] >= 0 && dist2[i] >= 0 && max(dist1[i], dist2[i]) < ans){
                ans = max(dist1[i], dist2[i]);
                ansnode = i;
            }
        }
        return ansnode;
    }
};