class Solution {
public:
    int booths(string S){
        int n = S.size(), k = 0, i = 0;
        vector<int> f(2 * n, -1);
        for (int j = 1; j < 2 * n; ++j){
            i = f[j - k - 1];
            while (i != -1 && S[j % n] != S[(k + 1 + i) % n]){
                if (S[j % n] < S[(k + i + 1) % n]){
                    k = j - i - 1;
                }
                i = f[i];
            }
            if (i == -1 && S[j % n] != S[(k + i + 1) % n]){
                if (S[j % n] < S[(k + i + 1) % n]){
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        return k;
    }
    
    string orderlyQueue(string s, int k) {
        if (k == 1){
            int rotate = booths(s);
            return s.substr(rotate) + s.substr(0, rotate);
        }
        sort(s.begin(), s.end());
        return s;
    }
};