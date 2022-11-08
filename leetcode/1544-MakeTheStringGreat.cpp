class Solution {
public:
    string makeGood(string s) {
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur){
            if (end > 0 && abs(s[end-1] - s[cur]) == 32){
                --end;
            } else {
                s[end++] = s[cur];
            }
        }
        return s.substr(0, end);
    }
};