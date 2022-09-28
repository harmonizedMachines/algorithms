class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long temp = 0, mi = 0, ma = 0;
        for (auto i: differences){
            temp += i;
            mi = min(mi, temp);
            ma = max(ma, temp);
        }
        return max(0L, upper-lower-(ma-mi)+1);
    }
};