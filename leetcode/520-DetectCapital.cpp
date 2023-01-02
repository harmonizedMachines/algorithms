class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (int i = 1; i < word.size(); ++i){
            if (isupper(word[i])){
                ++count;
            }
        }
        if (count == 0 || isupper(word[0]) && count == word.size() - 1){
            return true;
        }
        return false;
    }
};