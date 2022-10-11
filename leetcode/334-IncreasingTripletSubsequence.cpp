class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX, second = INT_MAX;
        for (auto i: nums){
            if (i <= smallest){
                smallest = i;
            } else if (i <= second){
                second = i;
            } else {
                return true;
            }
        }
        return false;
    }
};