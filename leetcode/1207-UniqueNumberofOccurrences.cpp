class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i: arr){
            ++m[i];
        }
        unordered_set<int> freq;
        for (auto [key, value]: m) {
            freq.insert(value);
        }
        return freq.size() == m.size();
    }
};