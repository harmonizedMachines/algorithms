class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        unordered_map<int, int> map;
        for (auto word: words){
            int mask = 0;
            for (auto c: word){
                mask |= 1 << (c - 'a');
            }
            map[mask] = max(map[mask], (int)word.size());
            for (auto item: map){
                if (!(item.first & mask))
                    result = max(result, (int)word.size() * item.second);
            }
        }
        return result;
    }
};