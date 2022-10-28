class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto s: strs){
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for (auto entry: map){
            res.push_back(entry.second);
        }
        return res;
    }
};