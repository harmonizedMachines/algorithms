class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return memo(0, 0, nums, multipliers);
    }
    
    int memo(int i, int l, vector<int>& nums, vector<int>& multipliers){
        if (i == m){
            return 0;
        }
        if (dp[i][l] != INT_MIN){
            return dp[i][l];
        }
        int left = memo(i + 1, l +1, nums, multipliers) + multipliers[i] * nums[l];
        int right = memo(i + 1, l, nums, multipliers) + multipliers[i] * nums[n-(i-l)-1];
        return dp[i][l] = max(left, right);
    }
};