class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counts;
        for (int task: tasks){
            ++counts[task];
        }
        int ans = 0;
        for (auto& c: counts){
            if (c.second == 1){
                return -1;
            }
            ans += c.second / 3 + (c.second % 3 ? 1: 0);
        }
        return ans;
    }
};