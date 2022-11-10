class Solution {
public:
    string removeDuplicates(string s) {
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur){
            if (end > 0 && s[cur] == s[end-1]){
                end--;
            } else {
                s[end++] = s[cur];
            }
        }
        return s.substr(0, end);
    }
};