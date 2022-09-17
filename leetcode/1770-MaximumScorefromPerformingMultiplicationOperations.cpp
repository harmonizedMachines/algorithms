class Solution {
public:
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp;
        int left = dp[i - 1][] + multipliers[] * nums[i];
        int right = dp[][] + multipliers[] * nums[i];
        dp[i][l] = max(left, right)
    }
};