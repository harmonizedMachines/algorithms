class Solution {
public:
    int numDecodings(string s) {
        int res = 1, lastres = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i){
            int curr = s[i] == '0' ? 0: res;
            if (i < n - 1 && (s[i] == '1' || (s[i+1] < '7' && s[i] == '2'))){
                curr += lastres;
            }
            lastres = res;
            res = curr;
        }
        return res;
    }
};