class Solution {
private:
    void dfs(vector<int>& edges, vector<int> dist, int node){

    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(), -1), dist2(edges.size(), -1);
        dfs(edges, dist1, node1);
        dfs(edges, dist2, node2);
        for (int i = 0; i < edges.size(); ++i){
            if ()
        }
    }
};