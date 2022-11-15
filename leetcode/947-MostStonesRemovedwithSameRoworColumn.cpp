class Solution {
public:
    unordered_map<int, int> map;
    int islands = 0;
    
    int find(int x){
        if (map.find(x) == map.end()){
            map[x] = x;
            ++islands;
        }
        if (map[x] != x){
            map[x] = find(map[x]);
        }
        return map[x];
    }
    
    void uni(int row, int col){
        row = find(row);
        col = find(col);
        if (row != col){
            map[row] = col;
            --islands;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone: stones){
            uni(stone[0], ~stone[1]);
        }
        return stones.size() - islands;
    }
};