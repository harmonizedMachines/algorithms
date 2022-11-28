class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> dp(100001, -1);
        for (auto& match: matches) {
            dp[match[1]] = dp[match[1]] == -1 ? 1: dp[match[1]] + 1;
            dp[match[0]] = dp[match[0]] == -1 ? 0: dp[match[0]];
        }
        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < dp.size(); ++i) {
            switch (dp[i]){
                case 0:
                    ans[0].push_back(i);
                    break;
                case 1:
                    ans[1].push_back(i);
                    break;
            }
        }
        return ans;
    }
};