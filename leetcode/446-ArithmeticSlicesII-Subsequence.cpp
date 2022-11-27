class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long,int>> cnt(nums.size());
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                if (cnt[j].find(diff) != cnt[j].end()){
                    cnt[i][diff] += cnt[j][diff];
                    ans += cnt[j][diff];
                }
                ++cnt[i][diff];
            }
        }
        return ans;
    }
};