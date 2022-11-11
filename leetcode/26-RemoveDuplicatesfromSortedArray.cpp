class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = 0;
        for (int cur = 0; cur < nums.size(); ++cur){
            if (end == 0 || nums[cur] != nums[end - 1]){
                nums[end++] = nums[cur];
            }
        }
        return end;
    }
};