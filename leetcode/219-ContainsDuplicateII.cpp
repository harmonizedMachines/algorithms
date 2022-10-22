class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 1){
            return false;
        }
        unordered_map<int, int> map;
        map[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++){
            if (map.find(nums[i]) != map.end()){
                if (i - map[nums[i]] <= k){
                    return true;
                }
            }
            map[nums[i]] = i;
        }
        return false;
    }
};