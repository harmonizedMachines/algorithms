class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), maxd;
        if (d > n) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int i = 1; i <= d; ++i){
            for (int j = 0; j <= n - i; ++j){
                maxd = 0, dp[j] = 1e9;
                for (int k = j; k <= n - i; ++k){
                    maxd = max(maxd, jobDifficulty[k]);
                    dp[j] = min(dp[j], maxd + dp[k + 1]);
                }
            }
        }
        return dp[0];
        
    }
};