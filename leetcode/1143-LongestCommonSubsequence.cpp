class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[2][1001] = {0};
        for (int i = 0; i < text1.size(); ++i){
            for (int j = 0; j < text2.size(); ++j){
                dp[(i + 1) % 2][j + 1] = text1[i] == text2[j] ? dp[i % 2][j] + 1: max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
            }
        }
        return dp[text1.size() % 2][text2.size()];
    }
};