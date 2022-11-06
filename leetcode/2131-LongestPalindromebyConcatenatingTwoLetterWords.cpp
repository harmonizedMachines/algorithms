class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for (auto word: words){
            ++map[word];
        }
        bool center = false;
        int res = 0;
        for (auto entry: map){
            if (entry.first[0] == entry.first[1]){
                res += entry.second / 2 * 4;
                if (entry.second % 2){
                    center = true;  
                }
            } else if (entry.first[0] < entry.first[1] && map.find({entry.first[1], entry.first[0]}) != map.end()){
                res += 4 * min(entry.second, map[{entry.first[1], entry.first[0]}]);
            }
        }
        return center ? res + 2 : res;
    }
};