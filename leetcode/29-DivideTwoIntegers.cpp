class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long a = abs(dividend), b = abs(divisor);
        long res = 0, i;
        while (a >= b){
            for (i = 0; a - (b << i << 1) >= 0; i++);
            res += 1 << i;
            a -= b << i;
        }
        return (dividend > 0) == (divisor > 0) ? res: -res;
    }
};