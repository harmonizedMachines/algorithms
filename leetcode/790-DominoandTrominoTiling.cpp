class Solution {
public:
    int numTilings(int n) {
        long dp[3] = {1, 2, 5};
        for (int i = 2; i < n - 1; ++i){
            dp[(i + 1) % 3] = (2 * dp[i % 3] + dp[(i - 2) % 3]) % 1000000007;
        }
        return dp[(n - 1) % 3];
    }
};