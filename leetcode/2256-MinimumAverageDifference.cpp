class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), ans = 0, mini = INT_MAX;
        long totalsum = 0, leftsum = 0;
        for (int i: nums){
            totalsum += i;
        }
        for (int i = 0; i < n; ++i){
            leftsum += nums[i];
            int dividend = i != n - 1 ? n - i - 1: 1;
            int diff = abs(leftsum / (i + 1) - (totalsum - leftsum) / dividend);
            if (mini > diff){
                mini = diff, ans = i;
            }
        }
        return ans;
    }
};