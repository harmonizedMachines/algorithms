class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int map[26] = {};
        for (char c: p){
            map[c - 'a']++;
        }
        int count = p.size(), i = 0, j = 0;
        vector<int> ans;
        while (j < s.size()){
            if (map[s[j++] - 'a']-- > 0){
                count--;
            }
            if (count == 0){
                ans.push_back(i);
            }
            if (j - i == p.size() && map[s[i++] - 'a']++ >= 0){
                count++;
            }
        }
        return ans;
    }
};