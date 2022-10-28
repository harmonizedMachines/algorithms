class Solution {
public:
    const static int N = 127;
    int dp[N][N];
    int n;
    string S;
    
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        S = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, k);
    }
    
    int solve(int left, int k){
        if (k < 0){
            return N;
        }
        if (left >= n || k >= n - left){
            return 0;
        }
        if (dp[left][k] != -1){
            return dp[left][k];
        }
        dp[left][k] = N;
        int most = 0;
        int cnt[26] = {0};
        for (int j = left; j < n; j++){
            most = max(most, ++cnt[S[j] - 'a']);
            dp[left][k] = min(dp[left][k], getLength(most) + solve(j+1, k - (j - left + 1 - most)));
        }
        return dp[left][k];
    }
    
    inline int getLength(int l){
        return l == 1 ? 1 : l < 10 ? 2 : l < 100 ? 3: 4;
    }
};