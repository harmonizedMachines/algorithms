class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        visited[0] = 1;
        queue<int> hi;
        hi.push(0);
        while (!hi.empty()){
            int now = hi.front();
            hi.pop();
            for (int i: rooms[now]){
                if (!visited[i]){
                    visited[i] = 1;
                    hi.push(i);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                return false;
            }
        }
        return true;
    }
};