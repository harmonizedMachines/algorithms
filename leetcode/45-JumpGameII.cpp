class Solution {
public:
    int jump(vector<int>& nums) {
        int maxrange = 0, jumps = 0, n = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            maxrange = max(maxrange, i + nums[i]);
            if (i == n){
                ++jumps;
                n = maxrange;
            }
        }
        return jumps;
    }
};