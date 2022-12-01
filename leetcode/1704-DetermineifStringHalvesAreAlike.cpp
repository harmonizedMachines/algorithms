class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size() - 1;
        int vowels1 = 0, vowels2 = 0;
        while (i < j){
            if (vowels.find(s[i]) != vowels.end()) {
                ++vowels1;
            }
            if (vowels.find(s[j]) != vowels.end()) {
                ++vowels2;
            }
            ++i, --j;
        }
        return vowels1 == vowels2;
    }
};