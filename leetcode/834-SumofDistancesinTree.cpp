class Solution {
public:
    vector<vector<int>> tree;
    vector<int> res, count;
    void dfs(int root, int prev){
        for (int i: tree[root]){
            if (i == prev){
                continue;
            }
            dfs(i, root);
            count[root] += count[i];
            res[root] += count[i] + res[i];
        }
    }

    void dfs2(int root, int prev){
        for (int i: tree[root]){
            if (i == prev){
                continue;
            }
            res[i] = count.size() - count[i] + res[root] - count[i];
            dfs2(i, root);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);
        for (auto& edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
};