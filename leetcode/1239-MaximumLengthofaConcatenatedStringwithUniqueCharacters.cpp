class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto &s: arr){
            bitset<26> letters;
            for (char c: s){
                letters.set(c - 'a');
            }
            if (letters.count() < s.size()) {
                continue;
            }
            for (int i = 0; i < dp.size(); i++){
                bitset<26> b = dp[i];
                if ((b & letters).any()){
                    continue;
                }
                dp.push_back(b | letters);
                res = max(res, (int)(b.count() + letters.count()));
            }
        }
        return res;
    }
};