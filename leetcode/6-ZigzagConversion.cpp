class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        vector<string> ans(numRows, "");
        int step = 0, row = 0;
        for (char c: s){
            ans[row] += c;
            if (row == numRows - 1){
                step = -1;
            }
            if (row == 0){
                step = 1;
            }
            row += step;
        }
        string com;
        for (auto r: ans){
            com += r;
        }
        return com;
    }
};