class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = n; i < nums.size(); ++i){
            nums[i] = (nums[i] << 10) | nums[i - n];
        }
        int index = 0;
        for (int i = n; i < nums.size(); ++i){
            nums[index++] = nums[i] & 1023;
            nums[index++] = nums[i] >> 10;
        }
        return nums;
    }
};