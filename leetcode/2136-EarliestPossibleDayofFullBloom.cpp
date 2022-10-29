class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> blooms;
        for (int i = 0; i < plantTime.size(); ++i){
            blooms.push_back({growTime[i], plantTime[i]});
        }
        sort(blooms.begin(), blooms.end());
        int days = 0;
        for (auto [g, p]: blooms){
            days = max(days, g) + p;
        }
        return days;
    }
};