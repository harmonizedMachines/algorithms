class Solution {
public:
    int numSquares(int n) {
        if (n <= 0){
            return 0;
        }
        static vector<int> squares = {0};
        while (squares.size() <= n){
            int m = squares.size();
            int prev = INT_MAX;
            for (int i = 1; i * i <= m; ++i) {
                prev = min(prev, squares[m - i * i] + 1);
            }
            squares.push_back(prev);
        }
        return squares[n];
    }
};