class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int p2i[26] = {};
        unordered_map<string, int> w2i;
        istringstream in(s);
        int i = 0;
        for (string word; in >> word; ++i){
            if (i == pattern.size() || p2i[pattern[i] - 'a'] != w2i[word]){
                return false;
            }
            p2i[pattern[i] - 'a'] = w2i[word] = i + 1;
        }
        return i == pattern.size();
    }
};