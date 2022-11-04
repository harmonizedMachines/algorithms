class Solution {
public:
    string reverseVowels(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end){
            start = s.find_first_of("aeiouAEIOU", start);
            end = s.find_last_of("aeiouAEIOU", end);
            if (start < end){
                swap(s[start++], s[end--]);
            }
        }
        return s;
    }
};