class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
        unordered_map<int, int> count;
        for (auto i: changed){
            count[i]++;
        }
        vector<int> key;
        for (auto i: count){
            key.push_back(i.first);
        }
        vector<int> res;
        sort(key.begin(), key.end(), [](int a, int b){ return abs(a) < abs(b);});
        for (auto i: key){
            if (count[i] > count[2 * i]) return {};
            for (int j = 0; j < count[i]; count[2*i]--, j++){
                res.push_back(i);
            }
        }
        return res;
    }
};