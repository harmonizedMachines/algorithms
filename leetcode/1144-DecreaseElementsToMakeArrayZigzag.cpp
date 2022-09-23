class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res[] = {0, 0};
        for (int i = 0; i < nums.size(); i++){
            int left = i - 1 < 0 ? 1001: nums[i-1];
            int right = i + 1 >= nums.size() ? 1001: nums[i + 1];
            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
        }
        return min(res[0], res[1]);
    }
};