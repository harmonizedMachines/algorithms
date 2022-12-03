class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char c: s){
            ++cnt[c];
        }
        vector<pair<int, char>> sortCnt;
        for (auto& [k, v]: cnt){
            sortCnt.push_back({v, k});
        }
        sort(sortCnt.begin(), sortCnt.end());
        string ans = "";
        ans.reserve(s.size());
        for (auto rit = sortCnt.rbegin(); rit != sortCnt.rend(); ++rit){
            ans += string(rit->first, rit->second);
        }
        return ans;
    }
};