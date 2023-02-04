class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {};
        for (char c: s1){
            map[c - 'a']++;
        }
        int count = s1.size(), i = 0, j = 0;
        while (j < s2.size()){
            if (map[s2[j++] - 'a']-- > 0){
                count--;
            }
            if (count == 0){
                return true;
            }
            if (j - i == s1.size() && map[s2[i++] - 'a']++ >= 0){
                count++;
            }
        }
        return false;
    }
};