class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int cnt = 0;
        for (int i = 0; i < capacity.size(); ++i){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (int c: capacity){
            if (additionalRocks - c >= 0){
                additionalRocks -= c;
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};