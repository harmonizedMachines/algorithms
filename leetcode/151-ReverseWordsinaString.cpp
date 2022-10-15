class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int stored = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] != ' '){
                if (stored != 0) s[stored++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' '){
                    s[stored++] = s[j++];
                }
                reverse(s.begin() + stored - (j - i), s.begin() + stored);
                i = j;
            }
        }
        s.erase(s.begin() + stored, s.end());
        return s;
    }
};