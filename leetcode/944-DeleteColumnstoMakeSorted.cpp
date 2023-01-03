class Solution {
private:
    int count = 0;

public:
    int minDeletionSize(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); ++i){
            int prev = -1;
            for (int j = 0; j < strs.size(); ++j){
                if (strs[j][i] < prev){
                    ++count;
                    break;
                }
                prev = strs[j][i];
            }
        }
        return count;
    }
};