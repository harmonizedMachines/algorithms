class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int minflip = 0, ones = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '1'){
                ++ones;
            } else {
                ++minflip;
            }
            minflip = min(minflip, ones);
        }
        return minflip;
    }
};