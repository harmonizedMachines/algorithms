class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int>& seq, vector<int>& nums, int i){
        if (seq.size() > 1){
            ans.push_back(seq);
        }
        unordered_set<int> hash;
        for (int p = i; p < nums.size(); ++p){
            if ((seq.size() == 0 || nums[p] >= seq.back()) && hash.find(nums[p]) == hash.end()){
                seq.push_back(nums[p]);
                dfs(seq, nums, p + 1);
                seq.pop_back();
                hash.insert(nums[p]);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        dfs(seq, nums, 0);
        return ans;
    }
};