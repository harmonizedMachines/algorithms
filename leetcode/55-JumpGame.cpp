class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for (int reach = 0; i < nums.size() && reach >= i; ++i){
            reach = max(reach, nums[i] + i);
        }
        return i == nums.size();
    }
};