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

    int numSquaresMath(int n) {
        if ((int)sqrt(n) * (int)sqrt(n) == n) {
            return 1;
        }
        // Legendre's three-square theorem
        while ((n & 3) == 0){
            n >>= 2;
        }
        if ((n & 7) == 7) {
            return 4;
        }
        int sqrt_n = sqrt(n);
        for (int i = 0; i < sqrt(n); ++i) {
            int tmp = n - i * i;
            if ((int)sqrt(tmp) * (int)sqrt(tmp) == tmp) {
                return 2;
            }
        }
        return 3;
    }
};