class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = 0, currmax = 0, currmin = 0, maxsum = INT_MIN, minsum = INT_MAX;
        for (auto& num: nums){
            totalsum += num, currmax += num, currmin += num;
            maxsum = max(maxsum, currmax);
            minsum = min(minsum, currmin);
            if (currmin > 0){
                currmin = 0;
            }
            if (currmax < 0){
                currmax = 0;
            }
        }
        return totalsum == minsum ? maxsum: max(maxsum, totalsum - minsum);
    }
};