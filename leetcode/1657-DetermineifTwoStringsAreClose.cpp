class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0), letters1(26, 0), letters2(26, 0);
        for (auto c: word1){
            ++cnt1[c - 'a'];
            letters1[c - 'a'] = 1;
        }
        for (auto c: word2){
            ++cnt2[c - 'a'];
            letters2[c - 'a'] = 1;
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2 && letters1 == letters2;
        
    }
};