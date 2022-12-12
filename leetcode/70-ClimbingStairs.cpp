class Solution {
public:
    int climbStairs(int n) {
        int temp[2] = {1, 2};
        for (int i = 2; i < n; i++){
            temp[i % 2] = temp[0] + temp[1];
        }
        return temp[(n + 1) % 2];
    }
};