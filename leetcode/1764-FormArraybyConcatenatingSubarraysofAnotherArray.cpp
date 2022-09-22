class Solution {
public:
    int m, n;
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums, int i, int j) {
        if (i >= m) return true;
        for (; j <= nums.size() - groups[i].size(); j++){
            for (int gi = 0; gi <= groups[i].size(); gi++){
                if (gi == groups[i].size()){
                    return canChoose(groups, nums, i + 1, j + groups[i].size());
                }
                if (groups[i][gi] != nums[j + gi]){
                    break;
                }
            }
        }
        return false;
    }
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        m = groups.size();
        n = nums.size();
        return canChoose(groups, nums, 0, 0);
        
    }
};