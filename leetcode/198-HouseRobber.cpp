class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2] = {0, 0};
        for (int i = 0; i < nums.size(); ++i){
            dp[(i + 1) % 2] = max(dp[i % 2], dp[(i + 1) % 2] + nums[i]);
        }
        return dp[nums.size() % 2];
    }
};