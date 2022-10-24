class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target + 1);
        int i, j, k;
        dp[0] = 1;
        for (i = 1; i <= d; ++i){
            for (j = target; j >= (target == d ? target: 0); --j){
                for (k = j - 1, dp[j] = 0; k >= max(0, j - f); --k){
                    dp[j] = (dp[j] + dp[k]) % 1000000007;
                }
            }
        }
        return dp[target];
    }
};