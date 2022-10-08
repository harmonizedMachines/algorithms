class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size() - 2; ++first){
            if (first > 0 && nums[first] == nums[first-1]){
                continue;
            }
            int second = first + 1, third = nums.size() - 1;
            while (second < third){
                int currSum = nums[first] + nums[second] + nums[third];
                if (abs(target - currSum) < abs(target - closest)){
                    closest = currSum;
                }
                if (currSum == target){
                    return currSum;
                }
                else if (currSum < target){
                    ++second;
                }
                else {
                    --third;
                }
            }
        }
        return closest;
    }
};