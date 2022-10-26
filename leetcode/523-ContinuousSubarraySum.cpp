class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int mod = 0, pre = 0;
        unordered_set<int> modk;
        for (int n: nums){
            mod = (mod + n) % k;
            if (modk.find(mod) != modk.end()) {
                return true;
            }
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};